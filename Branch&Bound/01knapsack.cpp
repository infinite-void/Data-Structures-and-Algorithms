#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* In this approach of 01knapsack problem, we consider 
 * the 2 cases for each element that is within given
 * capacity of knapsack. For given element with index i is within the given
 * capacity of knapsack we take the maximum values of these 2 case:
 * 	1. elementvalue + value of knapsack with capacity reduced by the weight
 * 	   of element which is fill by the items indexed i + 1 to n - 1.
 * 	2. ignore the element the take value for the knapsack filled
 * 	   by items indexed i + 1 to n - 1.
 * If the ith element exceeds the capacity by weight we just ignore the 
 * element and try to fill knapsack with elements indexed from i + 1 to n - 1.
 */

int maxValueKnapsack(vector<int> weights, vector<int> values, int start, int end, int capacity) {
	if(start == end || capacity < 1) 
		return 0;
	if(capacity < weights[start])
		return maxValueKnapsack(weights, values, start + 1, end, capacity);
	
	return max( maxValueKnapsack(weights, values, start + 1, end, capacity),
		    values[start] + maxValueKnapsack(weights, values, start + 1, end, capacity - weights[start]));
}

int main() {
	int n; //number of items
	cin >> n;
	
	vector<int> weights(n, 0);
	for(int i = 0; i < n; i++) 
		cin >> weights[i];

	vector<int> values(n , 0);
	for(int i = 0; i < n; i++)
		cin >>values[i];

	int knapsackCapacity;
	cin >> knapsackCapacity;

	cout << maxValueKnapsack(weights, values, 0, n, knapsackCapacity) << endl;
	return 0;
}
