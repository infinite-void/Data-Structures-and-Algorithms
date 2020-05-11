/*Consider a directed graph whose vertices are numbered from 1 to n. There is an edge from a vertex i to a vertex j iff either j = i + 1 or j = 3i. The task is to find the minimum number of edges in a path in G from vertex 1 to vertex n.

Input: 
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows.

Each test case contains a value of n. 

Output: 
Print the number of edges in the shortest path from 1 to n.

Constraints:
1<=T<=30
1<=n <=1000

Example:
Input:
2
9
4

Output:
2
2
*/

//Refer djikstra2 for adjacecny matrix

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
int findmin(vector<int> dist, vector<bool> vis) {
    int maxx=10001;
    int ret=0;
    for(int i=0;i<dist.size();i++) {
        if(dist[i]<maxx && !vis[i]) {
            maxx=dist[i];
            ret=i;
        }
    }
    return ret;
}
void solve() {
    ll n;
    cin>>n;
    ll d, s=1;
    d=n;
    vector<int> dist(n,10000);
    vector<bool> vis(n,false);
    dist[s-1]=0;
    for(int i=0;i<n-1;i++) {
        int src = i+1;
        vis[src-1]=true;
        int d1 = 3*(src);
        if(d1<=d && dist[d1-1]>dist[src-1]+1) dist[d1-1]=dist[src-1]+1;
        d1 = src+1;
        if(d1<=d && dist[d1-1]>dist[src-1]+1) dist[d1-1]=dist[src-1]+1;
    }
    cout<<dist[d-1]<<endl;
}
int main() {
    ll t;
    cin>>t;
    while(t--) solve();
	return 0;
}