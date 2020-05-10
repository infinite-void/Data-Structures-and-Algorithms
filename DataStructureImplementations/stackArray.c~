#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Stack {
	unsigned capacity;
	int top;
	int* array;	
}Stack;

Stack* createStack(unsigned size) {
	Stack* stack    = (Stack*)malloc(sizeof(Stack));
	
	stack->capacity = size;
	stack->top      = -1;
	stack->array    = (int*)malloc(size *  sizeof(int));

	return stack;
}

bool isEmpty(Stack* stack) {
	if(stack->top == -1)
		return true;
	return false;
}

bool isFull(Stack* stack) {
	if(stack->top == stack->capacity - 1)
		return true;
	return false;
}

void push(Stack* stack, int element) {
	if(isFull(stack)) {
		printf("Stack is full with %d elements. Cannot add new elements.(Stack overflow)\n", stack->capacity);
		return;
	}
	stack->top = stack->top + 1;
	stack->array[stack->top] = element;
	printf("Element %d has been pushed into the stack.\n", stack->array[stack->top]);
	return;
}

void pop(Stack* stack) {
	if(isEmpty(stack)) {
		printf("Stack is empty. Cannot pop out elements.\n");
		return;
	}
	int element = stack->array[stack->top];
	stack->top = stack->top - 1;
	printf("Element %d has been popped out of stack.\n", element);
	return;
}

int peek(Stack* stack) {
	if(isEmpty(stack)) {
		printf("Stack is empty. No element on top.\n");
		return INT_MIN;
	}
	return stack->array[stack->top];
}
int main() {
	unsigned size;
	int top, element, response;
	Stack* stack = NULL;

	printf("Enter the size of stack :");
	scanf("%u", &size);
	
	stack = createStack(size);
	
	if(stack == NULL) {
		printf("Error in stack creation. Exiting...\n");
		return 0;
	}

operation:
	printf("\n");
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
			push(stack, element);
			break;
		case 2:
			pop(stack);
			break;
		case 3:
			top = peek(stack);
			if(top != INT_MIN) 
				printf("Element on top is %d.\n", top);
			break;
		case 4:
			free(stack->array);
			free(stack);
			return 0;
		default:
			printf("Enter a proper response.");
	}
	goto operation;

	return 0;
}

