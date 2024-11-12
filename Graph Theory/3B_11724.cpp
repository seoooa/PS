#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj(1001);
vector<int> visited(1001, 0);

void dfs(int here) {

	visited[here] = 1;

	for (int i = 0; i < adj[here].size(); i++) {
		int next = adj[here][i];
		if (visited[next] == 0) dfs(next);
	}
}
int main() {

	int N, M, u, v, cnt = 0;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= N; i++) {
		if (visited[i] == 0) {
			cnt++;
			dfs(i);
		}
	}

	cout << cnt;
}