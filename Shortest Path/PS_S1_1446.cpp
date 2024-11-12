#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<pair<int, int>>> adj(10001);
vector<int> dst(10001, 1e9 + 1);
priority_queue<pair<int, int>> pq;

void Dijkstra() {
	while (pq.size()) {
		int hdst, here;
		hdst = -pq.top().first;
		here = pq.top().second;
		pq.pop();

		if (hdst > dst[here]) continue;

		for (int i = 0; i < adj[here].size(); i++) {
			int next, ndst;
			next = adj[here][i].first;
			ndst = hdst + adj[here][i].second;

			if (ndst < dst[next]) {
				dst[next] = ndst;
				pq.push({-ndst, next});
			}
		}
	}
}

int main() {

	int N, D;
	cin >> N >> D;

	for (int i = 0; i < D; i++) {
		adj[i].push_back({ i + 1, 1 });
	}

	for (int i = 0; i < N; i++) {
		int u, v, w;
		cin >> u >> v >> w;

		adj[u].push_back({ v, w });
	}

	pq.push({ 0, 0 });
	Dijkstra();

	cout << dst[D];

	return 0;
}