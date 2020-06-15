#include <stdio.h>
#include <stdlib.h>

void mergeSort(int*, int, int);
void merge(int*, int, int, int);

int main() {
	int n; //number of elements
	int i;
	scanf("%d", &n);
	
	int* array = (int*) calloc(n, sizeof(int));
	
	if(!array) {
		fprintf(stderr, "Could not allocate memory. Terminating. \n");
		return -1;
	}

	for(i = 0; i < n; i++) 
		scanf("%d", &array[i]);

	mergeSort(array, 0, n - 1);

	for(i = 0; i < n; i++) 
		printf("%d ", array[i]);
	printf("\n");
	free(array);
	return 0;
}
/* The mergesort() function implements the
 * divide and conquer approach where the array
 * is divided into 2 halves and recursed.
 * This recursion goes on till the array has only 
 * one element. An array with one element is self-sorted 
 * returns without any operations.
 * The merge operation merges the left and right parts of 
 * the array in linear time.
 * This way mergesort() divides the array on it way down 
 * to an input array of one element and merges back in
 * sorted order on its way up!
 * Hence, Divided and Conquered
 */
void mergeSort(int* array, int left, int right) {
	if(left >= right)
		return;
	
	int mid = (left + right) / 2;
	mergeSort(array, left, mid);
	mergeSort(array, mid + 1, right);
	
	merge(array, left, mid, right);
}

/*The merge operation uses temporary memory to merge
 * the 2 sorted parts of the array
 */

void merge(int* array, int left, int mid, int right) {
	int size = right - left + 1;
	int i = left, j = mid + 1, k = 0;
	int* temp = (int*) calloc(size, sizeof(int));
	
	if(!temp) {
		fprintf(stderr, "Error in allocating temporary memory. \n");
		exit(-1);
	}
	
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
