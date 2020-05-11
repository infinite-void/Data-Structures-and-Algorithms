/*Given N and E, the number of nodes and edges in a directed graph. The task is to do Breadth First Search of this graph.

Input:
The first line of the input contains an integer 'T' denoting the number of test cases. Then 'T' test cases follow. Each test case consists of two lines. Description of testcases is as follows: The First line of each test case contains two integers 'N' and 'E'  which denotes the no of vertices and no of edges respectively. The Second line of each test case contains 'E'  space separated pairs u and v denoting that there is a edge from u to v .

Output:
For each testcase, print the BFS of the graph starting from 0.

Note: The expected output button always produces BFS starting from node 0.

User Task:
Since, this is a functional problem, your task is to complete the function bfs() which do BFS of the given graph starting from node 0 and prints the nodes in BFS order.

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
3 2
0 1 0 2

Output:
0 1 2 3 4    // BFS from node 0
0 1 2

Explanation:
Testcase 1: 
0 is connected to 1 , 2 , 3
2 is connected to 4
so starting from 0 , bfs will be 0 1 2 3 4.
*/
#include<bits/stdc++.h>
using namespace std;

void bfs(int s, vector<int> adj[], bool vis[], int N)
{
    // Your code here
    queue<int> q;
    q.push(s);
    vis[s]=true;
    cout<<s<<" ";
    while(!q.empty()) {
        int src = q.front();
        q.pop();
        for(int i=0;i<adj[src].size();i++) {
            if(!vis[adj[src][i]]) {
                vis[adj[src][i]]=true;
                cout<<adj[src][i]<<" ";
                q.push(adj[src][i]);
            }
        }
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
        vector<int> adj[N];
        bool vis[N] = {false};
        for(int i=0;i<E;i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
        }
        
        bfs(0, adj, vis, N);

        cout<<endl;

    }
}
