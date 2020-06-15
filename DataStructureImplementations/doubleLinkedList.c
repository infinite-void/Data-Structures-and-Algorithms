//Author: infinite-void
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* struct LinkedListNode reprsents a single
 * node of a linked list.
 */

typedef struct LinkedListNode {
	int value;
	struct LinkedListNode* nextNode;
	struct LinkedListNode* prevNode;
}LinkedListNode;

/* struct LinkedList represents the 
 * Node itself.
 */
typedef struct LinkedList {
	LinkedListNode* front;
	LinkedListNode* rear;
}LinkedList;

/* creates a listNode with given data 
 * return pointer to it.
 */
LinkedListNode* createListNode(int element) {
	LinkedListNode* listNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));

	if(!listNode) {
		fprintf(stderr, "Error in node creation.\n");
		return NULL;
	}
	listNode->value = element;
	listNode->nextNode = NULL;
	listNode->prevNode = NULL;

	return listNode;
}

/* Alloctes memory to a list and
 * return pointer to it.
 */

LinkedList* createList() {
	LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
	
	if(!list) {
		fprintf(stderr, "Error in list creation.\n");
		return NULL;
	}
	list->front = NULL;
	list->rear = NULL;
	
	return list;
}

/* Gets a new node with data. append the front of the
 * list to its next pointer and makes the new node the
 * front of the list.
 * Either of front or rear pointer being NULL denotes 
 * an empty list
 */

void insertFront(LinkedList* list, int element) {
	LinkedListNode* listNode = createListNode(element);

	if(listNode == NULL) {
		fprintf(stderr, "Error in node creation.\n");
		return;
	}

	if(list->front == NULL) {
		//when the list is initially empty.
		list->front = listNode;
		list->rear = listNode;
		return;
	}
	(list->front)->prevNode = listNode;
	listNode->nextNode = list->front;
	list->front = listNode;
	return;
}

/* Gets a new node with data, appends it to the rear node
 * and makes the new node the new rear node.
 */

void insertRear(LinkedList* list, int element) {
	LinkedListNode*  listNode = createListNode(element);

	if(listNode == NULL) {
		fprintf(stderr, "Error in node creation.\n");
		return;
	}
	
	if(list->rear == NULL) {
		//when the list is initially empty.
		list->front = listNode;
		list->rear = listNode;
		return;
	}
	listNode->prevNode = list->rear;
	(list->rear)->nextNode = listNode;
	list->rear = listNode;
	return;
}

/* makes the list->front->next the list->front
 * and frees up the node.
 */

void removeFront(LinkedList* list) {
	if(list->front == NULL) {
		printf("List is empty. Cannot remove elements.\n");
		return;
	}

	LinkedListNode* rem = list->front;
	list->front = (list->front)->nextNode;

	if(list->front == NULL) {
		//the list is empty.
		list->rear = NULL;
	}
	else {
		list->front->prevNode = NULL;
	}

	free(rem);
	return;
}

/* makes the list->rear->prev the list->rear
 * and frees up the node.
 */

void removeRear(LinkedList* list) {
	if(list->rear == NULL) {
		printf("List is empty. Cannot remove elements.\n");
		return;
	}

	LinkedListNode* rem = list->rear;
	list->rear = (list->rear)->prevNode;

	if(list->rear == NULL) {
		//the list is empty
		list->front = NULL;
	}
	else {
		list->rear->nextNode = NULL;
	}

	free(rem);
	return;
}
//prints the list
void printList(LinkedList* list) {
	LinkedListNode* iterator = list->front;
	while(iterator != NULL) {
		printf("%d ", iterator->value);
		iterator = iterator->nextNode;
	}
	printf("\n");
	return;
}


int main() {
	LinkedList* list = createList();
	insertFront(list, 1);
	printList(list);
	insertFront(list, 2);
	printList(list);
	insertRear(list, 3);
	printList(list);
	insertRear(list, 4);
	printList(list);
	insertFront(list, 5);
	printList(list);
	insertRear(list, 6);
	printList(list);
	removeFront(list);
	printList(list);
	removeRear(list);
	printList(list);
	removeFront(list);
	printList(list);
	removeRear(list);
	printList(list);
	removeFront(list);
	printList(list);

}
