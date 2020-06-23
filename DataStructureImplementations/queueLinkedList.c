//Author: infinite-void
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* This struct represents a node in a 
 * linked list to form a queue
 */
typedef struct QueueNode {
	int value;
	struct QueueNode* nextNode;
}QueueNode;

/* This struct represent the queue itself
 */
typedef struct Queue {
	QueueNode* front;
	QueueNode* rear;
}Queue;

/* This method creates allocated memory 
 * to initialise a queue
 */

Queue* createQueue() {
	Queue* queue = (Queue*)malloc(sizeof(Queue));
	
	if(queue == NULL) {
		fprintf(stderr, "Error in initialising queue.\n");
		return NULL;
	}

	queue->front = NULL;
	queue->rear  = NULL;
	return queue;
}

/* THis method initialises a queueNode 
 * with a given data value
 */

QueueNode* createQueueNode(int element) {
	QueueNode* queueNode = (QueueNode*)malloc(sizeof(QueueNode));

	if(queueNode == NULL) {
		fprintf(stderr, "Error in creating node.\n");
		return NULL;
	}

	queueNode->value = element;
	queueNode->nextNode = NULL;
	
	return queueNode;
}

/* This method get a new Node with the data 
 * and adds the rearNode. It also changes the
 * rear pointer to the newly created node.
 * Either of queue->front or queue->rear 
 * being NULL represents a NULL queue.
 */

void Enqueue(Queue* queue, int element) {
	QueueNode* queueNode = createQueueNode(element);

	if(queueNode == NULL) {
		fprintf(stderr, "Error in Node creation.\n");
		return;
	}

	if(queue->rear == NULL) {
		queue->rear = queueNode;
		queue->front = queueNode;
		return;
	}

	(queue->rear)->nextNode = queueNode;
	queue->rear = queueNode;
	return;
}
 
/* This method return with message if queue is empty.
 * If not it makes the queue->front->next the 
 * queue->front and frees up the space used by the node.
 * if queue->front becomes NULL it denotes an empty queue
 * and sets queue->rear to NULL to clear the queue.
 */

void Dequeue(Queue* queue) {
	
	if(queue->front == NULL) {
		printf("Queue is empty. Cannot remove elements.\n");
		return;
	}

	QueueNode* deq = queue->front;
	queue->front = (queue->front)->nextNode;
	
	if(queue->front == NULL) 
		queue->rear = NULL;

	printf("Element %d is removed from queue.\n", deq->value);
	free(deq);
	return;
}

/* The front and rear method return INT_MIN
 * with a message if queue is empty. If not 
 * they return data value at front anfd rear of the
 * queue respectively.
 */

int Front(Queue* queue) {
	if(queue->front == NULL) {
		printf("Queue is empty. No elements.\n");
		return INT_MIN;
	}
	return (queue->front)->value;
}

int Rear(Queue* queue) {
	if(queue->rear == NULL) {
		printf("Queue is empty. No elements.\n");
		return INT_MIN;
	}
	return (queue->rear)->value;
}

int main() {

	int element, front, rear, response;
	Queue* queue = NULL;
	QueueNode* queueNode = NULL;

	queue = createQueue();
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
			if(queue == NULL) {
				fprintf(stderr, "Error in queuing.\n");
				return -1;
			}
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
			while(queue->front != NULL) {
				queueNode = queue->front;
				queue->front = (queue->front)->nextNode;
				printf("Free up node with %d.\n", queueNode->value);
				free(queueNode);
			}
			free(queue);
			return 0;
		default:
			printf("Enter a valid option.\n");
	}
	goto operation;
	return 0;
}
