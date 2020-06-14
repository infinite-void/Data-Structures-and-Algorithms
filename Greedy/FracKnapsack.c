/* Author: Keshav
Please report any bugs to the issue tracker on GitHub
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int profit;
	int weight;
}item;

/*
	The below function is used by the standard library's "qsort" routine to sort our array of structures
	
	The rules for such a function are:
	1) Return a number > 0 if the first element should come after the second element in the sorted list
	2) Return a number < 0 if the second element should come after the second element in the sorted list
	3) Return 0 if the elements are equal
	
	quicksort is an unstable sort, but that will not affect the overall profit, so it is fine to use the standard library routine (which may not even be quicksort)
*/

int compar(const void* a, const void* b)
{
	const item *x = (const item *) a;
	const item *y = (const item *) b;
	
	/* Typecasting one of the integers to float will ensure that the compiler promotes the other to a float and does a floating point division */
	
	float r1 = (((float) x->profit) / x->weight);
	float r2 = (((float) y->profit) / y->weight);

	return ( (r1 < r2) - (r1 > r2) );
}


int main(void) 
{
	int C, N, i;;
	int weight_so_far = 0;
	float Total_Profit = 0;
	item* list;
	
	printf("Enter the capacity of the knapsack: ");
	scanf("%d", &C);
	
	printf("Enter the number of items: ");
	scanf("%d", &N);
	
	/* Dynamically allocate an array of structures of suitable size */
	list = (item *) malloc(N * sizeof(item));
	
	if (!list) {
		printf("Dynamic memory allocation failed!\n");
		return (-1);
	}
	
	printf("Enter the item's profit and weight in space separated pairs: ");
	
	for (i = 0; i < N; i++) {
		scanf("%d %d", &list[i].profit, &list[i].weight);
		
		if (list[i].weight == 0) {
			printf("Please do not give any items with a weight of 0\n");
			return (-1);
		}
	}
	
	/* Sort the array in order of Profit to Weight ratio - this will ensure that we can select the best (greedy) choice at every iteration */
	/* This step takes N log N time */
	qsort(list, N, sizeof(item), compar);
	
	/* The algorithm now follows */
	i = 0;
	while (weight_so_far < C) {
		/* At each step, we choose the item remaining with the best Profit to Weight ratio */
		
		/* If the entire item can be added to the knapsack, do so */
		if (list[i].weight < (C - weight_so_far)) {
			weight_so_far += list[i].weight;
			Total_Profit += list[i].profit;
			i++;
		}
		
		/* Otherwise add the fractional part - whatever part that fills the rest of the knapsack */
		/* (Wremaining / Witem) * Pitem gives the profit that can be obtained by the fraction */
		else {
			Total_Profit += ( (((float)(C - weight_so_far)) / list[i].weight) * list[i].profit );
			weight_so_far = C;
			
			/* Technically, once a fractional part is added, the knapsack will always be full, so we can just break here */
		}
	}
	
	printf("The total profit that can be obtained is %f\n", Total_Profit);
	
	return 0;
}

/* Suggested exercises
	1) Other than printing the total profit, print out the selected fraction of each item and the contribution it makes to the profit 
	2) 1), but print out the items in the order in which they were accepted, without modifying the algorithm
		Hint: you can modify the struct to store any additional information you may need
		
	Related to 2)
	Given a list of numbers, remove any duplicates, while preserving the order of the numbers
	Eg i/p: 2 3 1 2 5 3 1 6 7
	Eg o/p: 2 3 1 5 1 6 7
*/