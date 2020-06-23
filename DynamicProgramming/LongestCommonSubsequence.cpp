#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/* To solve the problem we construct a table with n1 number of 
 * rows and n2 number of columns where n1 and n2 are the lengths
 * of string1 and string2 repectively.
 * When either or both the string is empty(length is zero),
 * the common subsqeunce is zero(pretty trivial).
 * 	dp[i][j] contains the length of longest common subsequence
 * 		 in the first i characters of string 1 and first j
 * 		 characters of string 2.
 * 	if string1[i - 1] == string2[j - 1] 
 * 		this particular character 
 * 		forms a part of common subsequence and so we add
 * 		this 1 character to the common subsequence from 
 * 		from the sources 0 to i - 2 to string1 and
 * 		0 to j - 2 of string2.
 * 	if string1[i - 1] != string2[j - 1]
 * 		we ignore the particular character and we pick the 
 * 		maximum length of subsequence from 0 to i - 2 of
 *		string1 and 0 to j - 2 of string2
 */
string LongestCommonSubsequence(string s1, string s2) {
	int n1 = s1.size();
	int n2 = s2.size();
	int dp[n1 + 1][n2 + 1];

	for(int i = 0; i <= n1; i++) 
		for(int j = 0; j <= n2; j++) 
			if(i == 0 || j == 0) 
				dp[i][j] = 0;
			else if(s1[i - 1] == s2[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else 
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
	
	cout << "Length of the Longest Common Subsequence : " << dp[n1][n2] << endl;

	string result = "";
	int i = n1, j = n2;
	while(i > 0 && j > 0) {
		if(s1[i - 1] == s2[j - 1]) {
			result += s1[i - 1];
			i--;
			j--;
		}
		else if(dp[i - 1][j] > dp[i][j - 1]) 
			i--;
		else 
			j--;
	}
	reverse(result.begin(), result.end());
	return result;
}

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	cout <<	LongestCommonSubsequence(s1, s2) << endl;
	return 0;
}
