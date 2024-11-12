#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> adj(300001);
vector<int> discovered(300001, 0);
queue<int> q;
vector<int> dst(300001);

void bfs() {
	while (q.size() > 0) {
		int here = q.front();
		q.pop();

		for (int i = 0; i < adj[here].size(); i++) {
			int next = adj[here][i];

			if (discovered[next] == 0) {
				q.push(next);
				discovered[next] = 1;
				dst[next] = dst[here] + 1;
			}
		}
	}
}

int main() {

	int N, M, K, X;
	cin >> N >> M >> K >> X;

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;

		adj[u].push_back(v);
	}

	q.push(X);
	discovered[X] = 1;
	dst[X] = 0;

	bfs();

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		if (dst[i] == K) {
			ans = 1;
			cout << i << endl;
		}
	}
	if (ans == 0) cout << -1;

	return 0;
}