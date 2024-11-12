#include <iostream>
#include <vector>
#include <queue>

using namespace std;

constexpr int INF = 1e9 + 1;
vector <vector<pair<int, int>>> adj(1001);
vector<int> dst(1001, INF);
priority_queue<pair<int, int>> pq;

void dijkstra() {

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
				pq.push({ -ndst, next });
			}
		}
	}
}

int main() {

	int N, M, start, end;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		adj[a].push_back({ b, c });
	}

	cin >> start >> end;
	
	pq.push({ 0, start });
	dst[start] = 0;

	dijkstra();

	cout << dst[end];

	return 0;
}