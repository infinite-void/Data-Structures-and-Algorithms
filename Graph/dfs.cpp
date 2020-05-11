/*Given N nodes and E edges of a connected undirected graph. The task is to do depth first traversal of the graph.

Note: Use recursive approach.

Input:
The first line of the input contains an integer 'T' denoting the number of test cases. Then 'T' test cases follow. Each test case consists of two lines. Description of testcases is as follows: The First line of each test case contains two integers 'N' and 'E'  which denotes the no of vertices and no of edges respectively. The Second line of each test case contains 'E'  space separated pairs u and v denoting that there is a edge from u to v .

Output:
For each testcase, print the nodes while doing DFS starting from node 0.

Your task:
The task is to complete the function dfs() which should do the depth first traversal of given graph and prints the node in DFS order.

Constraints:
1 <= T <= 100
2 <= N <= 104
1 <= E <= (N*(N-1))/2
Graph doesn't contain multiple edges and self loops.

Example:
Input:
2
5 4
0 1 0 2 0 3 2 4
4 3
0 1 1 2 0 3

Output:
0 1 2 4 3   
0 1 2 3

Explanation:
Testcase 1:
0 is connected to 1 , 2 , 3
1 is connected to 0
2 is connected to 0 and 4
3 is connected to 0
4 is connected to 2
so starting from 0 , dfs will be 0 1 2 4 3.
*/
#include<bits/stdc++.h>
using namespace std;

void dfs(int s, vector<int> g[], bool vis[])
{
    
    // Your code here
    vis[s]=true;
    cout<<s<<" ";
    for(int i=0;i<g[s].size();i++){
        if(!vis[g[s][i]])
            dfs(g[s][i], g,vis);
    }

}


int main()
{
    int T;
    cin>>T;
    while(T--)
    {

        int N, E;
        cin>>N>>E;
        
        vector<int> g[N];
        bool vis[N];
        
        memset(vis, false, sizeof(vis));
        
        for(int i=0;i<E;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        dfs(0,g,vis);
        
        cout<<endl;

    }
}  