#include <iostream>
#include <vector>

using namespace std;

constexpr int INF = 1e9 + 1;

vector<vector<pair<int, int>>> adj(1001);
vector<int> dst(1001, INF);

int main() {

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		adj[a].push_back({ b,c });
	}

	dst[1] = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < adj[i].size(); j++) {
			int u = i;
			int v = adj[i][j].first;
			int w = adj[i][j].second;

			if (dst[u] != INF) dst[v] = min(dst[u] + w, dst[v]);
		}
	}

	bool negative_cycle = false;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < adj[i].size(); j++) {
			int u = i;
			int v = adj[i][j].first;
			int w = adj[i][j].second;

			if (dst[u] != INF && dst[u] + w < dst[v]) negative_cycle = true;
			if (dst[u] != INF) dst[v] = min(dst[u] + w, dst[v]);
		}
	}

	if (negative_cycle) cout << -1;
	else {
		for (int i = 2; i <= N; i++) {
			if (dst[i] == INF) cout << -1 << "\n";
			else cout << dst[i] << "\n";
		}
	}

	return 0;
}