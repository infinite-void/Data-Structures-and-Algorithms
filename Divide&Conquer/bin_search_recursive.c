/* Author: Keshav */

#include <stdio.h>
#include <stdlib.h> 

int binary_search(int* array, int search, int start, int end)
{
	/* Condition for termination: Element is not found */
    if (start > end)
        return -1;
    
	/* This gives the first of the middle elements for even length sequences, and the exact middle for odd length  */
    int mid = start + (end - start) / 2;
    
	/* If the required element is in the middle, stop */
    if (array[mid] == search) 
        return mid;
	/* If the element is less than the middle element, search in the first half*/
    else if (array[mid] > search)
        return binary_search(array, search, start, mid - 1);
	/* If not, search in the second half */
    else
        return binary_search(array, search, mid + 1, end);
}

int main(void) 
{
    int N, i, search;
    int* array;
    
    printf("Enter the size of the array: ");
    scanf("%d", &N);
    
    /* Dynamically allocate memory for the array */
    array = (int *) malloc(sizeof(int) * N);
    
    if (!array) {
        fprintf(stderr, "Could not allocate memory!\n");
        return -1;
    }

    printf("Enter the %d numbers (which are in sorted order): ", N);
    
    for(i = 0; i < N; i++) {
        scanf("%d", &array[i]);
    }
    
    printf("Enter the number to be searched: ");
    scanf("%d", &search);
        
    if ((i = binary_search(array, search, 0, N - 1)) == -1) 
        printf("Element not found!\n");
    
    else 
        printf("Element %d is present at location %d\n", search, i);
        
    return 0;
}