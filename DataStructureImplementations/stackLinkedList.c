//Author: infinite-void
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* The struct is node in a linked list
 * with fields for data and pointer to next node
 */

typedef struct StackNode {
	int value;
	struct StackNode* nextNode;
}StackNode;

/* createStackNode() takes in a integer values and
 * returns a pointer to a new stack node with 
 * the value in it and NULL pointer in field to
 * point to the next node
 */
StackNode* createStackNode(int element) {
	StackNode* stackNode    = (StackNode*)malloc(sizeof(StackNode));
	
	if(!stackNode) 
		return NULL;

	stackNode->value = element;
	stackNode->nextNode = NULL;

	return stackNode;
}

/*Takes in the pointer to the headNode
 * and returns true if headNode is NULL
 */

bool isEmpty(StackNode* stackNode) {
	if(stackNode == NULL)
		return true;
	return false;
}

/* It gets a new node with data to be added.
 * It appends the headNode to the newNode and 
 * makes the newNode the headNode to insert elements to the
 * top.
 */


void push(StackNode** stackNode, int element) {
	StackNode* newNode = createStackNode(element);

	if(newNode == NULL) {
		fprintf(stderr, "Error in node creation.\n");
		return;
	}
	newNode->nextNode = *stackNode;
	*stackNode = newNode;
	printf("Element pushed into stack is %d.\n", (*stackNode)->value);
	return;
}

/* This method checks if the stack is empty. If so
 * simply returns with a message else frees up the 
 * headNode space after transafer the headNode->next 
 * to the headNode field;
 */

void pop(StackNode** stackNode) {
	if(isEmpty(*stackNode)) {
		printf("Stack is empty. Cannot pop out elements.\n");
		return;
	}
	StackNode* toPop = *stackNode;
	*stackNode = (*stackNode)->nextNode;
	printf("Element popped out is %d.\n", toPop->value);
	free(toPop);
	return;
}

/* Returns the element on top
 * if stack is empty. Return INT_MIN
 * if stack is empty.
 */
int peek(StackNode** stackNode) {
	if(isEmpty(*stackNode)) {
		printf("Stack is empty. No element on top.\n");
		return INT_MIN;
	}
	return (*stackNode)->value;
	
}
int main() {
	int top, element, response;
	StackNode* stack = NULL;
	StackNode* temp = NULL;

operation:
	printf("1. Add element to stack.\n");
	printf("2. Pop element from stack.\n");
	printf("3. View top of stack.\n");
	printf("4. Quit\n");
	printf("Your response :");
	scanf("%d", &response);
	
	switch(response) {
		case 1:
			printf("Enter element to push :");
			scanf("%d", &element);
			push(&stack, element);
			if(stack == NULL) {
				fprintf(stderr, "Error in adding elements.\n");
				return -1;
			}
			break;
		case 2:
			pop(&stack);
			break;
		case 3:
			top = peek(&stack);
			if(top != INT_MIN) 
				printf("Element on top is %d.\n", top);
			break;
		case 4:
			while(stack!=NULL) {
				temp = stack;
				stack = stack->nextNode;
				printf("Free up node with %d.\n", temp->value);
				free(temp);
			}
			free(stack);
			return 0;
		default:
			printf("Enter a proper response.");
	}
	goto operation;

	return 0;
}

