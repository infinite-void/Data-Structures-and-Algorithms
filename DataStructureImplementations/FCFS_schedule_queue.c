//author: infinite-void
#include <stdio.h>
#include <stdlib.h>
#define PROCESS_SIZE 3

typedef struct process {
	int arrival_time;
	int burst_time;
	struct process* nextprocess;
}process;

typedef struct queue {
	struct process* front;
	struct process* rear;
}queue;

queue* createQueue() {
	queue* q = (queue*) malloc(sizeof(queue));
	if(q == NULL) {
		fprintf(stderr, "Error in creating queue.\n");
		return NULL;
	}

	q->front = NULL;
	q->rear = NULL;
	return q;
}

int empty(queue* q) {
	if(q->front == NULL || q->rear == NULL)
		return 1;
	return 0;
}

void push(queue* q, process* p) {

	if(empty(q)) {
		q->rear = p;
		q->front = p;
		return;
	}

	q->rear->nextprocess = p;
	q->rear = p;
	return;
}

void pop(queue* q) {
	if(empty(q)) {
		fprintf(stderr, "Queue empty. could not pop.");
		return;
	}
	
	process* p = q->front;
	q->front = p->nextprocess;

	if(empty(q)) 
		q->rear = NULL;
	
	return;
}

process* front(queue* q) {
	if(empty(q)) {
		fprintf(stderr, "Queue is empty.");
		return NULL;
	}
	return q->front;
}

process* rear(queue* q) {
	if(empty(q)) {
		fprintf(stderr, "Queue is empty.");
		return NULL;
	}
	return q->rear;
}
int compare(const void* a, const void* b) {
	const process* x = (const process*)a;
	const process* y = (const process*)b;
	return x->arrival_time > y->arrival_time;
}

void FCFS(queue* q) {
	int current_time  = 0;
	int waiting[PROCESS_SIZE], turnaround[PROCESS_SIZE];
	float avg_turnaround = 0, avg_waiting = 0;
	int i = 0;
	while(!empty(q)) {
		process* p = front(q);
		if(current_time < p->arrival_time) {
			current_time = p->arrival_time;
		}
		waiting[i] = current_time - p->arrival_time;
		current_time += p->burst_time;
		turnaround[i] = current_time - p->arrival_time;
		i++;
		pop(q);
	}
	fprintf(stdout, "Waiting\t Turnaroud\n");
	for(i = 0; i < PROCESS_SIZE; i++) {
		fprintf(stdout, "%d\t %d\n", waiting[i], turnaround[i]);
		avg_turnaround += turnaround[i];
		avg_waiting += waiting[i];
	}
	avg_waiting /= PROCESS_SIZE;
	avg_turnaround /= PROCESS_SIZE;
	fprintf(stdout, "Average Waiting Time: %.6f.\n", avg_waiting);
	fprintf(stdout, "Average Turnaround Time: %.6f.\n", avg_turnaround);

}
int main() {
	process p[PROCESS_SIZE];
	queue* q = createQueue();
	if(q == NULL) {
		fprintf(stderr, "Error in creating queue.\n");
		return -1;
	}

	int i;
	
	for(i = 0; i < PROCESS_SIZE; i++)  {
		scanf("%d %d", &p[i].arrival_time, &p[i].burst_time);
		p[i].nextprocess = NULL;
	}
	
	qsort(p, PROCESS_SIZE, sizeof(process), compare);
	
	for(i = 0; i < PROCESS_SIZE; i++)
		push(q, &p[i]);	

	FCFS(q);
	free(q);
	return 0;
}

