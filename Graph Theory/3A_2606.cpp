#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj(101);
vector<int> visited(101, 0);

void dfs(int here) {

	visited[here] = 1;
	
	for (int i = 0; i < adj[here].size(); i++) {

		int next = adj[here][i];
		if (visited[next] == 0) dfs(next);
	}
}

int main() {

	int N, M, v1, v2, cnt = 0;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> v1 >> v2;
		adj[v1].push_back(v2);
		adj[v2].push_back(v1);
	}

	dfs(1);

	for (int i = 1; i < N + 1; i++) {
		if (visited[i]) cnt++;
	}

	cout << cnt - 1;

	return 0;
}