#include<stdio.h>
#include<limits.h>
#define MAX 10
//Declare a variable to keep track of size of the heap.
int heap_size;

//create an array which will be our heap.
int heap[MAX];

//Returns the parent of index i
int parent(int i){
	return (i-1)/2;
}

//Returns the left child of index i
int left(int i){
	return (2*i)+1;
}

//Returns the right child of index i
int right(int i){
	return (2*i)+2;
}

//Function to swap two integers
void swap(int *a,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

//Inserting an element into the heap
//Check if the heap size is full.
//If it is not full enter the value at the last index.
//Make sure that there is no value lower than the newly inserted value at the top.
//In case any value is lower at the top, swap the values to make it a minheap
void insert(int x){
	if(heap_size>=MAX){
		printf("Heap size is full");
		return;
	}
	heap_size++;
	int i = heap_size-1;
	heap[i] = x;
	while(i!=0 && heap[i] < heap[parent(i)]){
		swap(&heap[i],&heap[parent(i)]);
		i = parent(i);
	}	
}

//This function decreases the value at the specified index and sets to "val".
//Make sure that there is no value lower than the newly inserted value at the top.
//In case any value is lower at the top, swap the values to make it a minheap
void decrease(int i,int val){
	heap[i] = val;
	while(i!=0 && heap[i] < heap[parent(i)]){
		swap(&heap[i],&heap[parent(i)]);
		i = parent(i);
	}
}
//This recursive function makes sure that the heap property is maintained.
//Whenever there is achange in the heap, it is recommended to execute the Minheapify function
void Minheapify(int i){
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if(l<heap_size && heap[l]<heap[smallest]){
		smallest = l;
	}
	if(r<heap_size && heap[r] < heap[smallest]){
		smallest = r;
	}
	if(smallest!=i){
		swap(&heap[i],&heap[smallest]);
		Minheapify(smallest);
	}
}

//This function removes the current element at the top of the heap.
//After removal, Minheapify is called to restore the heap property
int extractmin(){
	if(heap_size<=0){
		printf("Heap is empty");
	}
	if(heap_size == 1){
		heap_size--;
		return heap[0];
	}
	int temp = heap[0];
	heap[0] = heap[heap_size-1];
	heap_size--;
	Minheapify(0);
	return temp;
}

//This function deletes the value at current index.
//To do so, we decrease the value to INT_MIN and use extractmin()
void del(int i){
	decrease(i,INT_MIN);
	extractmin();	
}

//This function is used to retrieve the element at top of the heap
//No change is made to the heap
int getMin(){
	return heap[0];
}


int main(){
	int n;
	printf("Enter the no of elemennts to insert into the heap:");
	scanf("%d",&n);
	heap_size = 0;
	//You can use for loop to insert the required no of values into the heap.
	
	/*for(int i=0;i<n;i++){
		int x;
		cin>>x;
		insert(x);
	}*/
	
	//You can also manually insert or delete or perform any of the heap operations at any point of time.
	
	insert(3); 
    insert(2); 
    del(1); 
    insert(15); 
    insert(5); 
    insert(4); 
    insert(45); 
    printf("%d ",extractmin());
    printf("%d ",getMin()); 
    decrease(2, 1); 
    printf("%d ",getMin());  
}
	