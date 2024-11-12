#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> adj(50001);
vector<int> dst(50001, -1);
vector<int> discovered(50001, 0);
queue<int> q;

int max_dst = -1;

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

				if (dst[next] > max_dst) max_dst = dst[next];
			}
		}
	}
}

int main() {

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	q.push(1);
	discovered[1] = 1;
	dst[1] = 0;

	bfs();

	vector<int> ans;
	for (int i = 1; i <= N; i++) {
		if (dst[i] == max_dst) ans.push_back(i);
	}

	sort(ans.begin(), ans.end());

	cout << ans[0] << " " << max_dst << " " << ans.size();

	return 0;
}