//Author: infite-void
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* This struct completey denotes the queue
 * with a pointer to data container, front
 * rear indices, current size and maximum 
 * capacity/
 */
typedef struct Queue {
	unsigned capacity;
	int size, front, rear;
	int* array;
}Queue;

/* This method allocates the memory for 
 * data container and initializes the values in
 * the struct queue
 */

Queue* createQueue(unsigned size) {
	Queue* queue = (Queue*)malloc(sizeof(Queue));
	
	if(!queue) {
		fprintf(stderr, "Error in memory allocation. \n");
		return NULL:
	}
	queue->capacity = size;
	queue->size     = 0;
	queue->front    = 0;
	queue->rear     = -1;
	queue->array    = (int*)malloc(size * sizeof(int));

	return queue;
}

/* The size of the queue is tracked
 * with the size variable. this indicates a 
 * empty queue when zero and a full queue
 * when equal the queue->capacity
 */

bool isEmpty(Queue* queue) {
	if(queue->size == 0)
		return true;
	return false;
}

bool isFull(Queue* queue) {
	if(queue->size == queue->capacity)
		return true;
	return false;
}

/* This simply returns with a message when queue is full.
 * When not full the data value is added the rear of the
 * queue and the rear index is increased by one. the size 
 * variable is updated.
 */

void Enqueue(Queue* queue, int element) {
	if(isFull(queue)) {
		printf("Queue is full. Cannot add elements.\n");
		return;
	}
	queue->rear = (queue->rear + 1) % queue->capacity;
	queue->array[queue->rear] = element;
	queue->size = queue->size + 1;

	printf("Element %d added to Queue.\n", queue->array[queue->rear]);
	return;
}

/* This simply returns with a message when queue is empty.
 * This increases the front index of the queue and updates 
 * size variable. This dequeued values will be overwritten 
 * by another enqueued value at the same index.
 */

void Dequeue(Queue* queue) {
	if(isEmpty(queue)) {
		printf("Queue is empty. Cannot remove elements.\n");
		return;
	}
	int pop = queue->array[queue->front];
	queue->front = (queue->front + 1) % queue->capacity;
	queue->size = queue->size - 1;

	printf("Element %d is removed from queue.\n", pop);
	return;
}

/* Returns INT_MIN with a message whn empty and
 * returns element at front index if not.
 */

int Front(Queue* queue) {
	if(isEmpty(queue)) {
		printf("Queue is empty. No elements.\n");
		return INT_MIN;
	}
	return queue->array[queue->front];
}

/* Returns INT_MIN with a message when empty and
 * returns element at rear index if not.
 */

int Rear(Queue* queue) {
	if(isEmpty(queue)) {
		printf("Queue is empty. No elements.\n");
		return INT_MIN;
	}
	return queue->array[queue->rear];
}

int main() {
	unsigned size;
	int element, front, rear, response;
	Queue* queue = NULL;

	printf("Enter Queue size :");
	scanf("%u", &size);

	queue = createQueue(size);
	if(queue == NULL) {
		fprintf(stderr, "Error in queue creation.\n");
		return -1;
	}
operation:
	printf("\n");
	printf("1. Add elements to Queue.\n");
	printf("2. Remove elements from Queue.\n");
	printf("3. View Front of Queue.\n");
	printf("4. View Rear of Queue.\n");
	printf("5. Quit\n");
	printf("Enter your response :");
	scanf("%d", &response);

	switch(response) {
		case 1:
			printf("Enter element to add : ");
			scanf("%d", &element);
			Enqueue(queue, element);	
			break;
		case 2:
			Dequeue(queue);
			break;
		case 3:
			front = Front(queue);
			if(front != INT_MIN)
				printf("Element in front is %d.\n", front);
			break;
		case 4:
			rear = Rear(queue);
			if(rear != INT_MIN)
				printf("Element in rear is %d.\n", rear);
			break;
		case 5:
			free(queue->array);
			free(queue);
			return 0;
		default:
			printf("Enter a valid option.\n");
	}
	goto operation;
	return 0;
}
