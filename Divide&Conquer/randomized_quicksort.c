//Author: infinite-void 
#include <stdio.h>
#include <stdlib.h>

void quickSort(int*, int, int);
int partition(int*, int, int);
int getRandomIndex(int, int);
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


/* The randomized quicksort is same as the quicksort
 * algorithm except for the selection of partition 
 * element.
 */

void quickSort(int* array, int left, int right) {
	if(left >= right)
		return;
	int partedIndex = partition(array, left, right);
	quickSort(array, left, partedIndex - 1);
	quickSort(array, partedIndex + 1, right);
}

/* Picks a random index between the leftmost and
 * rightmost index of the array as the pivot element.
 * It then swaps the pivot element to the rightmost 
 * index and starts partitioning the array based on the pivot element.
 * This method is employed to avoid the case scenario where the input array
 * is in a strictly-non-increasing fashion. This case makes the time 
 * complexity O(n^2). By picking a random index this case
 * is almost improbabale.
 */

int partition(int* array, int left, int right) {
	
	int randomIndex = getRandomIndex(left, right);
	swap(&array[right], &array[randomIndex]);

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

/* The rand() function returns an integer in the
 * range of 0 and RAND_MAX(which is typically 32767, 
 * may vary depending on implementation). This rand() integer
 * is used to pick a random index between min_index and max_index
 */
int getRandomIndex(int min_index, int max_index) {
	return  min_index + (rand() %  (max_index - min_index + 1));
}

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
