#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> adj(1001);
vector<int> dst(1001, -1);
vector<int> discovered(1001, 0);
queue<int> q;

void bfs() {
	while (q.size() > 0) {
		int here = q.front();
		q.pop();

		for (int i = 0; i < adj[here].size(); i++) {
			int next = adj[here][i];

			if (!discovered[next]) {
				discovered[next] = 1;
				q.push(next);

				dst[next] = dst[here] + 1;
			}
		}
	}
}

int main() {

	int a, b, N, M;
	cin >> a >> b >> N >> M;

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	q.push(a);
	discovered[a] = 1;
	dst[a] = 0;

	bfs();

	cout << dst[b];

	return 0;
}