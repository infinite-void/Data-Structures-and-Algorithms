//for an undirected graph
//uses adjacency matrix
//uses recursion
//single--source
//all the vertices may not be visited in 
//an undirected graph
#include <iostream>
#include <vector>
using namespace std;

void depthFirstSearch(int n, vector<vector<int>> adjMat, vector<bool>& visited, int source) {
	visited[source] = true;
	cout << source << " ";
	for(int i = 0; i < n; i++) {
		if(adjMat[source][i] && !visited[i])
			depthFirstSearch(n, adjMat, visited, i);
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
