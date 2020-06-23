/* Author: Keshav 
Please report any bugs to the issue tracker on GitHub
*/

#include <stdio.h>
#include <stdlib.h> 

/* Working:
   Mid gives the first of the middle elements for even length sequences, and the exact middle for odd length.
   
   If the required element is in the middle, stop.
   If the required element is less than array[mid], search the subarray a[start]...a[mid - 1] by setting end = mid - 1 and recursing
   If not, search the subarray a[mid + 1]...a[end] by setting start = mid + 1 and recursing
   
   Start > End means that there is no subarray to search - hence we terminate and return -1 to indicate that the element is not found
  */

int binary_search(int* array, int search, int start, int end)
{
    if (start > end)
        return -1;   
	
    int mid = start + (end - start) / 2;
    
    if (array[mid] == search) 
        return mid;
    else if (array[mid] > search)
        return binary_search(array, search, start, mid - 1);
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