#include <iostream>
#include <vector>
using namespace std;

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
