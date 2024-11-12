#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<pair<int, int>>> adj(300001);
priority_queue<pair<int, int>> pq;
vector<int> dst(20001, 1e9 + 1);

int main() {

	int V, E, start;
	scanf("%d %d %d", &V, &E, &start);

	for (int i = 0; i < E; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);

		adj[u].push_back({ v,w });
	}

	for (int i = 0; i < adj[start].size(); i++) {
		
		if (dst[adj[start][i].first] > adj[start][i].second) {
			dst[adj[start][i].first] = adj[start][i].second;
			pq.push({ (-1) * adj[start][i].second , adj[start][i].first });
		}
	}
	dst[start] = 0;

	int here, hdst, next, ndst;
	while (pq.size() > 0) {
		hdst = pq.top().first;
		here = pq.top().second;
		pq.pop();

		hdst *= -1;
		if (hdst > dst[here]) continue;

		for (int i = 0; i < adj[here].size(); i++) {

			next = adj[here][i].first;
			ndst = adj[here][i].second + hdst;

			if (dst[next] > ndst) {
				dst[next] = ndst;
				pq.push({ (-1) * ndst, next });
			}
		}
	}

	for (int i = 1; i <= V; i++) {
		if (dst[i] == 1e9 + 1) printf("INF\n");
		else printf("%d\n", dst[i]);
	}

	return 0;
}