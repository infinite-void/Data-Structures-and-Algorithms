#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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
