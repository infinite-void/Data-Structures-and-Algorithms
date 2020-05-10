#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Queue {
	unsigned capacity;
	int size, front, rear;
	int* array;
}Queue;

Queue* createQueue(unsigned size) {
	Queue* queue = (Queue*)malloc(sizeof(Queue));

	queue->capacity = size;
	queue->size     = 0;
	queue->front    = 0;
	queue->rear     = -1;
	queue->array    = (int*)malloc(size * sizeof(int));

	return queue;
}
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

int Front(Queue* queue) {
	if(isEmpty(queue)) {
		printf("Queue is empty. No elements.\n");
		return INT_MIN;
	}
	return queue->array[queue->front];
}

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
		printf("Error in queue creation.\n");
		return 0;
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
