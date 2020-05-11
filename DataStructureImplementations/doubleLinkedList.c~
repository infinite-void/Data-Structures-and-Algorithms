#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct LinkedListNode {
	int value;
	struct LinkedListNode* nextNode;
	struct LinkedListNode* prevNode;
}LinkedListNode;

typedef struct LinkedList {
	LinkedListNode* front;
	LinkedListNode* rear;
}LinkedList;
 
LinkedListNode* createListNode(int element) {
	LinkedListNode* listNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
	listNode->value = element;
	listNode->nextNode = NULL;
	listNode->prevNode = NULL;

	return listNode;
}

LinkedList* createList() {
	LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
	list->front = NULL;
	list->rear = NULL;
	
	return list;
}

void insertFront(LinkedList* list, int element) {
	LinkedListNode* listNode = createListNode(element);

	if(listNode == NULL) {
		printf("Error in node creation.\n");
		return;
	}

	if(list->front == NULL) {
		list->front = listNode;
		list->rear = listNode;
		return;
	}
	(list->front)->prevNode = listNode;
	listNode->nextNode = list->front;
	list->front = listNode;
	return;
}

void insertRear(LinkedList* list, int element) {
	LinkedListNode*  listNode = createListNode(element);

	if(listNode == NULL) {
		printf("Error in node creation.\n");
		return;
	}

	if(list->rear == NULL) {
		list->front = listNode;
		list->rear = listNode;
		return;
	}
	listNode->prevNode = list->rear;
	(list->rear)->nextNode = listNode;
	list->rear = listNode;
	return;
}
void removeFront(LinkedList* list) {
	if(list->front == NULL) {
		printf("List is empty. Cannot remove elements.\n");
		return;
	}

	LinkedListNode* rem = list->front;
	list->front = (list->front)->nextNode;

	if(list->front == NULL) {
		list->rear = NULL;
	}

	free(rem);
	return;
}

void removeRear(LinkedList* list) {
	if(list->rear == NULL) {
		printf("List is empty. Cannot remove elements.\n");
		return;
	}

	LinkedListNode* rem = list->rear;
	list->rear = (list->rear)->prevNode;

	if(list->rear == NULL) {
		list->front = NULL;
	}

	free(rem);
	return;
}
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
	insertFront(list, 7);
	printList(list);
	insertRear(list, 78);
	printList(list);
	insertFront(list,88);
	removeRear(list);
	printList(list);
	removeFront(list);
	printList(list);
	insertFront(list, 9);
	insertRear(list, 62);
	insertRear(list, 93);
	printList(list);
}
