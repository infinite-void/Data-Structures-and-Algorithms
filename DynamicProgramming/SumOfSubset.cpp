//Author: infinite-void
#include <iostream>
#include <vector>
using namespace std;

/*  Dynamic Programming here, invloves a tabulation of `expectedSum + 1` rows and columns equal to the 
    number of elements in the set.
    Here every cell is either true or false.
    `true` at dp[i][j] denotes that there exists a subset within the set of 0 to j - 1 elements
    that make up the sum i.
    `false` denotes that such subset does not exist.

    dp[i][j] can be true if dp[i][j - 1]. (Subset already exists and j -1 element doesnot matter).
    If j - 1 element is smaller or equal to i, dp[i][j] can be true if dp[i - `j-1 element`][j - 1],
    (j-1 element matters).

    dp[expectedSum][inputSet.size()] denotes if a subset with expectedSum exists in whole inputSet.
 */
bool dp_subsetSum(const vector<int>& inputSet, const int& expectedSum) {
    vector<vector<bool>> dp(expectedSum + 1, vector<bool>(inputSet.size() + 1, false));
    
    for(int i = 0; i < inputSet.size() + 1; i++) 
        dp[0][i] = true;

    for(int i = 1; i < expectedSum + 1; i++) {
        for(int j = 1; j < inputSet.size() + 1; j++) {
            if(inputSet[j - 1] <= i) 
                dp[i][j] = dp[i - inputSet[j - 1]][j - 1] || dp[i][j - 1];
            else 
                dp[i][j] = dp[i][j - 1];
        }
    } 
    return dp[expectedSum][inputSet.size()];
} 
int main() {
    int n, expectedSum;
    cout << "Enter number of elements :";
    cin >> n;

    vector<int> inputSet(n ,0);
    cout << "Enter set: ";
    for(int i = 0; i < n; i++) 
        cin >> inputSet[i]; 

    cout << "Enter expected sum :";
    cin >> expectedSum;

    if(dp_subsetSum(inputSet, expectedSum))
        cout << "such subset exists" << endl;
    else 
        cout << "such subset doesn't exist" << endl;
    return 0;
}