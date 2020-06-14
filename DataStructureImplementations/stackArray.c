// Author: infinite-void
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* The struct stack include 3 items:
 * 1. capacity - the maximum capacity of the stack as mentioned by the user in the beginnning. The size of the stack is 
 * fixed and cannot be altered
 * 2. top - this item always points to the index of the array that contains the top most element of the stack
 * 3. array - this item points to the data container that stores the element of the stack
*/
typedef struct Stack {
	unsigned capacity;
	int top;
	int* array;	
}Stack;

/* The createStack() method takes the maximum size of stack as input and 
 * initialises the stack capacity and top index. It mainly allocates memory 
 * for the data container to store elements of stack
 */

Stack* createStack(unsigned size) {
	Stack* stack    = (Stack*)malloc(sizeof(Stack));
	
	stack->capacity = size;
	stack->top      = -1;
	stack->array    = (int*)malloc(size *  sizeof(int));
	
	if(!stack->array) 
		return NULL;	
	
	return stack;
}

/* the stack->top pointing to -1 is out of scope for the data container
 * the top index being out of scope denotes the container is empty
 */

bool isEmpty(Stack* stack) {
	if(stack->top == -1)
		return true;
	return false;
}

/* Given the maximum capacity the index of the container cannot
 * exceed capacity - 1
 */

bool isFull(Stack* stack) {
	if(stack->top == stack->capacity - 1)
		return true;
	return false;
}


/* The stack is first checked it its full. If not the element
 * is added and the top index in incremented
 */

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

/* The stack is checked if its empty. If not the 
 * top index is decremented. The value will be 
 * overwritten when next next element is added 
 * in its position
 */
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

/* The stack is checked if its empty
 * if its not element in the top index of the 
 * array is returned
 */

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

