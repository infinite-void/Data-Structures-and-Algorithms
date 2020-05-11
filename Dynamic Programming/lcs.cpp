/*Given two sequences, find the length of longest subsequence present in both of them. Both the strings are of uppercase.

Input:
First line of the input contains no of test cases  T,the T test cases follow.
Each test case consist of 2 space separated integers A and B denoting the size of string str1 and str2 respectively
The next two lines contains the 2 string str1 and str2 .

Output:
For each test case print the length of longest  common subsequence of the two strings .

Constraints:
1<=T<=200
1<=size(str1),size(str2)<=100

Example:
Input:
2
6 6
ABCDGH
AEDFHR
3 2
ABC
AC

Output:
3
2

Explanation
LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3.

LCS of "ABC" and "AC" is "AC" of length 2
*/


#include<iostream>
#include<algorithm>
#define ll long long 

using namespace std;
void solve() {
    ll sa, sb;
    string a,b;
    cin>>sa>>sb;
    cin>>a>>b;
    int mat[sa+1][sb+1];
    for(int i=0;i<=sa;i++) mat[i][0]=0;
    for(int i=1;i<=sb;i++) mat[0][i]=0;
    for(int i=1;i<=sa;i++) {
        for(int j=1;j<=sb;j++) {
            if(a[i-1]==b[j-1]) mat[i][j]=mat[i-1][j-1]+1;
            else mat[i][j]=max(mat[i-1][j], mat[i][j-1]);
        }
    }
    cout<<mat[sa][sb]<<endl;
}
int main()
 {
	ll t;
	cin>>t;
	while(t--) solve();
	return 0;
}