#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> adj(101);
vector<int> discovered(101, 0);
queue<int> q;
vector<int> dst(101);

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

	int N, M, sum, min_sum = -1, ans;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	bfs();

	for (int i = 1; i <= N; i++) {

		for (int j = 1; j <= N; j++) {
			discovered[j] = 0;
			dst[i] = 0;
		}
		sum = 0;

		q.push(i);
		discovered[i] = 1;
		dst[i] = 0;

		bfs();

		for (int j = 1; j <= N; j++) {
			sum += dst[j];
		}

		if (min_sum == -1 || sum < min_sum) {
			min_sum = sum;
			ans = i;
		}
	}

	cout << ans;

	return 0;
}