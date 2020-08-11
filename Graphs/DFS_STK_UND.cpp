//Author: infinite-void

//for an undirected graph
//uses adjacency matrix
//uses recursion
//single-source all the vertices will not be
//visited in a disconnected graph 
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/* In this program the recursion is replaced by 
 * a stack. source vertex is pushed into the stack to begin
 * with. The top of the stack is visited if not and removed.
 * After pop the top the vertices adjacent to the popped out
 * vertex is pushed into the stack.
 */ 

void depthFirstSearch(int n, vector<vector<int>> adjMat, vector<bool>& visited, int source) {
	stack<int> graphStack;
	graphStack.push(source);
	while(!graphStack.empty()) {
		int src = graphStack.top();
		if(!visited[src]) {
			cout << src << " ";
			visited[src] = true;
		}
		graphStack.pop();
		for(int i = 0; i < n; i++) {
			if(adjMat[src][i] && !visited[i]) {
				graphStack.push(i);
			}
		}
	}
	
}
int main() {
	int n; //number of vertices
	int e; //number of edges
	cin >> n >> e;
	vector<vector<int>> adjMat(n, vector<int> (n, 0));

	for(int i = 0; i < e; i++) {
		int a, b;
		cin >> a >> b;
		adjMat[a][b] = 1;
		adjMat[b][a] = 1;
	}
	int source;
	cin >> source;
	vector<bool> visited(n, false);
	depthFirstSearch(n, adjMat, visited, source);
	cout << endl;
	return 0;
}
