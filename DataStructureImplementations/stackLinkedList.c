#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct StackNode {
	int value;
	struct StackNode* nextNode;
}StackNode;

StackNode* createStackNode(int element) {
	StackNode* stackNode    = (StackNode*)malloc(sizeof(StackNode));
	
	stackNode->value = element;
	stackNode->nextNode = NULL;

	return stackNode;
}

bool isEmpty(StackNode* stackNode) {
	if(stackNode == NULL)
		return true;
	return false;
}

void push(StackNode** stackNode, int element) {
	StackNode* newNode = createStackNode(element);

	if(newNode == NULL) {
		printf("Error in node creation.\n");
		return;
	}
	newNode->nextNode = *stackNode;
	*stackNode = newNode;
	printf("Element pushed into stack is %d.\n", (*stackNode)->value);
	return;
}

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

