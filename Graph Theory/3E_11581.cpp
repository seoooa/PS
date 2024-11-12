#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj(101);
vector<int> visited(101, 0);

int cycle = 0;

void dfs(int here) {

	if (cycle) return;
	visited[here] = 1;

	for (int i = 0; i < adj[here].size(); i++) {
		int next = adj[here][i];
		
		if (visited[next] == 1) {
			cycle = 1;
			return;
		}
		if (visited[next] == 0) dfs(next);
	}
	visited[here] = 2;
}
int main() {

	int N, M;
	cin >> N;

	for (int u = 1; u <= N -1; u++) {
		cin >> M;
		for (int j = 0; j < M; j++) {
			int v;
			cin >> v;
			adj[u].push_back(v);
		}
	}

	dfs(1);
	if (cycle) cout << "CYCLE";
	else cout << "NO CYCLE";

	return 0;
}