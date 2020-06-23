//Author: infinite-void
#include <iostream>
#include <vector>

using namespace std;
/* In the Dynamic Programming approach to the 01knapsack problem
 * we construct a table where each column represents an item (1 - indexed, 0 is ignored)
 * and ith row represents the knapsack with i capacity.
 * Given items of non-zero weights knapsack with 0 capacity can be filled only with zero value.
 * We assume is no item indexed 0. Hence,
 * 		dp[i][j] = 0 if i=0 or j=0;
 * When i >= weights[j-1]
 * 	i represents the capacity of knapsack. So if weight[j-1] is less than or equal to i
 * 	we can put it in the knapsack. So we compare the cases where the item j -1 is included and
 * 	excluded and we choosed the case with maximum value.
 * 	dp[i][j - 1] represents value of the knapsack in the case where the j - 1 item is excluded.
 * 	dp[i - weights[j - 1]][j - 1] represent the value of knapsack with weight[j - 1] free space. and j - 1
 * 	item can be included and value of j - 1 is added to the knapsack.
 * When i < weight[j - 1]
 * 	we exclude the item.
 */ 
int maxValueKnapsack(vector<int> weights, vector<int> values, int knapsackCapacity) {
	int dp[knapsackCapacity + 1][weights.size() + 1];

	for(int i = 0; i <= knapsackCapacity; i++) {
		for(int j = 0; j <= weights.size(); j++) {
			if(i == 0 || j == 0) 
				dp[i][j] = 0;
			else if(i >= weights[j - 1]) 
				dp[i][j] = max(dp[i][j - 1], values[j - 1] + dp[i - weights[j - 1]][j - 1]);
			else 
				dp[i][j] = dp[i][j - 1];
		}
	}
	return dp[knapsackCapacity][weights.size()];
}

int main() {
	int n; //total number of items
	cin >> n;

	vector<int> weights(n, 0);
	for(int i = 0; i < n; i++) 
		cin >> weights[i];

	vector<int> values(n, 0);
	for(int i = 0; i < n; i++)
		cin >> values[i];
	
	int knapsackCapacity;
	cin >> knapsackCapacity;

	cout << maxValueKnapsack(weights, values, knapsackCapacity) << endl;
	return 0;
}
