#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj(1001);
vector<int> visited(1001, 0);

int cycle = 0;

void dfs(int here) {

	visited[here] = 1;

	for (int i = 0; i < adj[here].size(); i++) {
		int next = adj[here][i];

		if (visited[next] == 1) {
			cycle++;
		}
		if (visited[next] == 0) dfs(next);
	}
	visited[here] = 2;
}

int main() {

	int T, N;
	cin >> T;

	for (int i = 0; i < T; i++) {

		cin >> N;

		for (int i = 0; i <= 1000; i++) {
			adj[i].clear();
			visited[i] = 0;
			cycle = 0;
		}

		for (int u = 1; u <= N; u++) {
			int v;
			cin >> v;

			adj[u].push_back(v);
		}

		for (int i = 1; i <= N; i++) {
			if (visited[i] == 0) dfs(i);
		}

		cout << cycle << endl;
	}

	return 0;
}