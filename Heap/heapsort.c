/* Author: Keshav */
#include <stdio.h>
#include <stdlib.h>

/* Heapsort makes use of the MaxHeap data structure which has the property that
   every element is >= its children
*/
 
/* sift_down function assumes that both the children trees are heaps.
   It then filters its element (root) down to a lower level to maintain the 
   heap property
    
   (heap_size / 2) - 1 gives the last possible parent/internal node
   (2 * root) + 1 will give root's left child
    
   if j < (heap_size - 1) => right child also exists
*/
 
void sift_down(int* heap, int heap_size, int root)
{
  int j;
  int key = heap[root]; 
    
  while (root <= ((heap_size / 2) - 1)) {
    j = (2 * root) + 1;
    
      if (heap[j] > key) {
        if (j < (heap_size - 1)) {
          if (heap[j] < heap[j + 1])
            j = j + 1;
        }
            
        heap[root] = heap[j];
        root = j;
      } 
      else 
        break;
  }
    
  heap[root] = key;
}

/* Call sift_down on all nodes on all internal nodes 
   Time complexity - O(n)
   
   You can also build a heap by repeated insertion, which will take 
   O(n log n) - this is more efficient
 */

void heapify(int* array, int array_size)
{
  int i = (array_size / 2) - 1;
    
  for (; i >= 0; i--) {
    sift_down(array, array_size, i);
  }
}
 
int print_array(int* array, int array_size)
{
  int i;

  for (i = 0; i < array_size; i++) {
    printf("%d ", array[i]);
  }
  
  printf("\n");
}

/* Working of heap sort:
   Swap root and last element
   Sift down the new root assuming that the heap_size has reduced by 1
   This will preserve the heap property
   
   Repeat till the heap_size becomes 1
*/
void heap_sort(int* heap, int heap_size)
{
  int temp;
  
  while (heap_size > 1) {
    heap_size--;
    
    temp = heap[0];
    heap[0] = heap[heap_size];
    heap[heap_size] = temp;
    
    sift_down(heap, heap_size, 0);
  }    
}

int main(void)
{
  int* heap, n, i;
  
  printf("Enter the number of elements: ");
  scanf("%d", &n);
  
  heap = (int *) malloc(sizeof(int) * n);
  
  if(!heap) {
    fprintf(stderr, "Could not allocate space for array!\n");
    return -1;
  }
  
  printf("Enter the %d elements: ", n);
  
  for(i = 0; i < n; i++) {
    scanf("%d", &heap[i]);
  }
  
  heapify(heap, n);
  heap_sort(heap, n);

  printf("The sorted array is:\n");
  print_array(heap,n);

  return 0;
}