// Author: Keshav, edited from Srinath's DFS implementation
// The implementation of BFS using Queue is symmetric to DFS with Stack

//for an undirected graph
//uses adjacency matrix
//uses recursion
//single-source all the vertices will not be
//visited in a disconnected graph 
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
 
void breadthFirstSearch(int n, vector<vector<int>> adjMat, vector<bool>& visited, int source) {
	queue<int> graphQueue;
	graphQueue.push(source);
	while(!graphQueue.empty()) {
		int src = graphQueue.front();
		if(!visited[src]) {
			cout << src << " ";
			visited[src] = true;
		}
		graphQueue.pop();
		for(int i = 0; i < n; i++) {
			if(adjMat[src][i] && !visited[i]) {
				graphQueue.push(i);
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
	breadthFirstSearch(n, adjMat, visited, source);
	cout << endl;
	return 0;
}
