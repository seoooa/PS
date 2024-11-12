#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> adj(1001);
vector<int> visited(1001, 0);
vector<int> discovered(1001, 0);
queue<int> q;

void dfs(int here) {

	if (!visited[here]) {
		visited[here] = 1;
		cout << here << " ";

		for (int i = 0; i < adj[here].size(); i++) {	
			dfs(adj[here][i]);
		}
	}
}

void bfs() {
	while (q.size() > 0) {
		
		int here = q.front();
		cout << here << " ";

		q.pop();

		for (int i = 0; i < adj[here].size(); i++) {
			if (!discovered[adj[here][i]]) {
				discovered[adj[here][i]] = 1;
				q.push(adj[here][i]);
			}
		}
	}
}

int main() {

	int N, M, V;
	cin >> N >> M >> V;

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= N; i++) {
		sort(adj[i].begin(), adj[i].end());
	}
	
	dfs(V);
	cout << "\n";

	q.push(V);
	discovered[V] = 1;
	bfs();

	return 0;
}