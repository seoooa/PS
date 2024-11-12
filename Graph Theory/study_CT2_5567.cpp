#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> adj(501);
vector<int> discovered(501, 0);
vector<int> dst(501, -1);
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

	int n, m, cnt = 0;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	discovered[1] = 1;
	dst[1] = 0;
	q.push(1);

	bfs();

	for (int i = 1; i <= n; i++) {
		if (dst[i] == 1 || dst[i] == 2) cnt++;
	}

	cout << cnt;

	return 0;
}