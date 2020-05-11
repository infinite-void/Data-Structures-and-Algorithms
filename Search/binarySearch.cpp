/*Given a sorted array arr[] of N integers and a number K is given. The task is to check if the element K is present in the array or not.

Input:
First line of input contains number of testcases T. For each testcase, first line of input contains number of elements in the array and the number K seperated by space. Next line contains N elements.

Output:
For each testcase, if the element is present in the array print "1" (without quotes), else print "-1" (without quotes).

Constraints:
1 <= T <= 100
1 <= N <= 106
1 <= K <= 106
1 <= arr[i] <= 106

Example:
Input:
2
5 6
1 2 3 4 6
5 2
1 3 4 5 6

Output:
1
-1

Explanation:
Testcase 1: Since, 6 is present in the array at index 4 (0-based indexing), so output is 1.
Testcase 2: Since, 2 is not present in the array, so output is -1.
*/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <bitset>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <array>
#include <unordered_map>
#include <unordered_set>
#define  ll long long
using namespace std;

int bs(int arr[], int l, int r, int k) {
    if(l > r) 
        return -1;
    int mid = (l+r)/2;
    if(arr[mid] == k) 
        return 1;
    else if(arr[mid] < k) 
        return bs(arr, mid + 1, r, k);
    else 
        return bs(arr, l,  mid-1, k);
}

void solve() {
    int n, k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<bs(arr, 0, n-1, k)<<endl;
    return;
}

int main() {
    int t;
    cin>>t;
    while(t--) solve();
	return 0;
}