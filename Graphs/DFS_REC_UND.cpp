//Author: infinite-void

//for an undirected graph
//uses adjacency matrix
//uses recursion
//single--source
//all the vertices may not be visited in 
//an undirected graph
#include <iostream>
#include <vector>

using namespace std;

/* Here we use and vector of vector as a adjacency matrix.
 * Since we deal with undirected graphs an edge between i
 * and j turns both adjMat[i][j] and adjMat[j][i] to 1.
 * Once we find a vertex j adjacent to i we recurse into 
 * a dfs of j before we find another adjacent vertex of i.
 */

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
