#include <stdio.h>
#include <stdlib.h>

void mergeSort(int*, int, int);
void merge(int*, int, int, int);

int main() {
	int n; //number of elements
	int i;
	scanf("%d", &n);
	
	int* array = (int*) calloc(n, sizeof(int));
	for(i = 0; i < n; i++) 
		scanf("%d", &array[i]);

	mergeSort(array, 0, n - 1);

	for(i = 0; i < n; i++) 
		printf("%d ", array[i]);
	printf("\n");
	free(array);
	return 0;
}

void mergeSort(int* array, int left, int right) {
	if(left >= right)
		return;
	
	int mid = (left + right) / 2;
	mergeSort(array, left, mid);
	mergeSort(array, mid + 1, right);
	merge(array, left, mid, right);
}

void merge(int* array, int left, int mid, int right) {
	int size = right - left + 1;
	int* temp = (int*) calloc(size, sizeof(int));
	int i = left, j = mid + 1, k = 0;
	
	while(i <= mid && j <= right) {
		if(array[i] < array[j]) {
			temp[k] = array[i];
			k++;
			i++;
		}
		else {
			temp[k] = array[j];
			k++;
			j++;
		}
	}
	while(i <= mid) {
		temp[k] = array[i];
		k++;
		i++;
	}
	while(j <= right) {
		temp[k] = array[j];
		k++;
		j++;
	}
	for(i = left; i <= right; i++) 
		array[i] = temp[i - left];
	free(temp);
}
