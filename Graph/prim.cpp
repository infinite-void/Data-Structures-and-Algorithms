/*Given a weighted, undirected and connected graph. The task is to find the sum of weights of  the edges of the Minimum Spanning Tree.

Input:
The first line of input contains an integer T denoting the number of testcases. Then T test cases follow. The first line of each testcase contains two integers N (starting from 1), E denoting the number of nodes and number of edges. Then in the next line are 3*E space separated values a b w where a, b denotes an edge from a to b and w is the weight of the edge.

Output:
For each test case in a new line print the sum of weights of  the edges of the Minimum Spanning Tree formed of the graph.

User task:
Since this is a functional problem you don't have to worry about input, you just have to complete the function  spanningTree() which takes a graph g as its argument and returns an integer denoting the sum of weights of the edges of the Minimum Spanning Tree.

Constraints:
1 <= T <= 10
1 <= N<= 100
N-1 <= E<= 1000
1 <= w <= 1000

Example:
Input:
2
3 3
1 2 5 2 3 3 1 3 1
2 1
1 2 5

Output:
4
5

Example:
Testcase 1:  Sum of weights of edges in the minimum spanning tree is 4.
*/



#include <bits/stdc++.h>
using namespace std;
int spanningTree(int V,int E,vector<vector<int> > graph);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int V,E;
        cin>>V>>E;
        vector< vector<int> > graph(V,vector<int>(V,INT_MAX));

        while(E--)
        {
            int u,v,w;
            cin>>u>>v>>w;
            u--,v--;
            graph[u][v] = w;
            graph[v][u] = w;
        }

        cout<<spanningTree(V,E,graph)<<endl;
    }
    return 0;
}
int findmin(vector<int> dist, vector<bool> vis) {
    int minn=10001;
    int ret=0;
    for(int i=0;i<dist.size();i++) {
        if(dist[i]<minn && !vis[i]) {
            ret=i;
            minn = dist[i];
        }
    }
    return ret;
}
int spanningTree(int V,int E,vector<vector<int> > graph)
{
    vector<int> parent(V, 0);
    vector<int> dist(V, 10000);
    vector<bool> vis(V, false);
    dist[0]=0;
    for(int i=0;i<V-1;i++) {
        int src = findmin(dist,vis);
        vis[src]=true;
        for(int j=0;j<V;j++) {
            if(!vis[j] && graph[src][j]!=INT_MAX && dist[j]>graph[src][j]) {
                dist[j] = graph[src][j];
                parent[j]=src;
            }
        }
    }
//PRINT PARENT ARRAY TO KNOW THE PARENT OF EACH NODE AND DIST ARRAY TO KNOW THE DISTANCE FROM IT
    int ret=0;
    for(int i=0;i<V;i++) {
        if(i!=parent[i])
            ret+= graph[i][parent[i]];
    }
    return ret;
}