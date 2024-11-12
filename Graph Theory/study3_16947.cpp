#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj(3001);
vector<int> visited(3001, 0);
int start, dst = 0, ans;
int visit_total = 0;
int N;
vector<int> pt;

void dfs(int here) {

	if (visited[here] == 1) {
		visited
	}

	if(!visited[here]) {
		visited[here] = 1;

		for (int i = 0; i < adj[here].size(); i++) {
			dfs(adj[here][i]);
		}

		visited[here] = 2;
	}
}

int main() {

	cin >> N;

	for (int i = 1; i <= N; i++) {
		int u, v;
		cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= N; i++) {
		if (adj[i].size() == 3) pt.push_back(i);
	}

	start = 1;
	dfs(start);
	cout << ans;

	return 0;
}