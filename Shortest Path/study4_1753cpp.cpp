#include <iostream>
#include <vector>
#include <queue>

using namespace std;

constexpr int INF = 1e9 + 1;

vector<vector<pair<int, int>>> adj(20001);
vector<int> dst(20001, INF);
priority_queue<pair<int, int>> pq;

void shortestPath() {
	while (pq.size() > 0) {
		int hdst = pq.top().first;
		int here = pq.top().second;

		pq.pop();

		hdst *= -1;
		if (hdst > dst[here]) continue;

		for (int i = 0; i < adj[here].size(); i++) {
			int next = adj[here][i].first;
			int ndst = adj[here][i].second;

			ndst += hdst;
			if (ndst < dst[next]) {
				dst[next] = ndst;
				pq.push(make_pair(-ndst, next));
			}
		}
	}
}

int main() {

	int V, E, K;
	cin >> V >> E >> K;
	
	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;

		adj[u].push_back(make_pair(v, w));
	}

	pq.push(make_pair(0, K));
	dst[K] = 0;
	
	shortestPath();

	for (int i = 1; i <= V; i++) {
		if (dst[i] == INF) cout << "INF";
		else cout << dst[i];

		cout << "\n";
	}

	return 0;
}