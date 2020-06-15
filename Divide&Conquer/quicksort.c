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
	
	if(!array) {
		fprintf(stderr, "Error in memory allocation for array. \n");
		return -1;
	}

	for(i = 0; i < n; i++) 
		scanf("%d", &array[i]);
	quickSort(array, 0, n - 1);

	for(i = 0; i < n; i++)
		printf("%d ", array[i]);
	printf("\n");

	free(array);
	return 0;
}


/* The quicksort employs divide and conquer approach 
 * such that it partitions the given array based on
 * a pivot element (partition may or may not be of 
 * equal sizes). The elements to the left of the pivot 
 * element are less than the pivot element and those on 
 * the right are greater than or equal to it.
 * Now, the left and right partitions are sorted recursively
 * based on partitioning.
 * Arbitrarily, the right most element is always chosen as pivot.
 * This may have an worst case time complexity of O(n^2).
 * Randomized QuickSort may make this worst case scenario almost improbable.
 */

void quickSort(int* array, int left, int right) {
	if(left >= right)
		return;
	int partedIndex = partition(array, left, right);
	quickSort(array, left, partedIndex - 1);
	quickSort(array, partedIndex + 1, right);
}

/* Partition the array into 2 parts and return 
 * index of the pivot element.
 */

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
