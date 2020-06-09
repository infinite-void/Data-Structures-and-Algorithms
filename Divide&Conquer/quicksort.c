#include <stdio.h>
#include <stdlib.h>

void quickSort(int*, int, int);
int partition(int*, int, int);
void swap(int*, int*);

int main() {
	int n; //number of elements
	int i;
	scanf("%d", &n);
	
	int* array = (int*)calloc(n , sizeof(int));
	for(i = 0; i < n; i++) 
		scanf("%d", &array[i]);
	quickSort(array, 0, n - 1);

	for(i = 0; i < n; i++)
		printf("%d ", array[i]);
	printf("\n");

	free(array);
	return 0;
}

void quickSort(int* array, int left, int right) {
	if(left >= right)
		return;
	int partedIndex = partition(array, left, right);
	quickSort(array, left, partedIndex - 1);
	quickSort(array, partedIndex + 1, right);
}

int partition(int* array, int left, int right) {
	int pivot = array[right];
	int partedIndex = left - 1;
	int i;
	for(i = left; i < right; i++) {
		if(array[i] < pivot) {
			partedIndex += 1;
			swap(&array[i], &array[partedIndex]);
		}
	}
	partedIndex += 1;
	swap(&array[partedIndex], &array[right]);
	return partedIndex;
}


void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
