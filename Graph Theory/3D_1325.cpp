#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj(100001);
vector<int> visited(100001, 0);
vector<int> hack_cnt(100001, 0);

int cnt, max_cnt = 0;

void dfs(int here) {
	
	visited[here] = 1;
	cnt++;

	for (int i = 0; i < adj[here].size(); i++) {
		int next = adj[here][i];
		if (visited[next] == 0) dfs(next);
	}
}
int main() {

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;

		adj[v].push_back(u);
	}

	for (int i = 1; i <= N; i++) {
		cnt = 0;
		for (int j = 1; j <= N; j++) visited[j] = 0;
		dfs(i);

		if (cnt >= max_cnt) max_cnt = cnt;
		hack_cnt[i] = cnt;
	}

	for (int i = 1; i <= N; i++) {
		if (hack_cnt[i] == max_cnt) cout << i << " ";
	}

	return 0;
}