#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj(101);
vector<int> visited(1001, 0);
vector<int> compare(1001, 0);

void dfs(int here) {

	if (!visited[here]) {
		visited[here] = 1;

		for (int i = 0; i < adj[here].size(); i++) {
			int next = adj[here][i];
			dfs(next);
		}
	}
}

int main() {

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;

		adj[u].push_back(v);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) compare[j] = 0;

		for (int j = 1; j <= N; j++) {
			for (int j = 1; j <= N; j++) visited[j] = 0;
			if (compare[j]) continue;
			
			if (j == i) {
				dfs(j);
				for (int k = 1; k <= N; k++) {
					if (visited[k]) compare[k] = 1;
				}
			}
			else {
				dfs(j);
				if (visited[i]) compare[j] = 1;
			}
		}

		int cnt = 0;
		for (int j = 1; j <= N; j++) {
			if (!compare[j]) cnt++;
		}

		cout << cnt << "\n";
	}
	
	return 0;
}