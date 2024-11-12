#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<pair<int, int>>> adj(1000001);
priority_queue<pair<int, int>> pq;
vector<int> dst(1000001, 1e9 + 1);

int main() {

	int m, n, start;
	scanf("%d %d", &m, &n);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int w;
			scanf("%d", &w);

			if (i == 0 && j == 0) start = w;

			if (w != -1) {
				if (j > 0) adj[i * n + j - 1].push_back({ i * n + j , w });
				if (j < n - 1) adj[i * n + j + 1].push_back({ i * n + j , w });
				if (i > 0) adj[(i - 1) * n + j].push_back({ i * n + j , w });
				if (i < n - 1) adj[(i + 1) * n + j].push_back({ i * n + j , w });
			}
		}
	}

	dst[0] = start;
	if (start == -1) {
		printf("-1");
		return 0;
	}

	pq.push({ (-1) * dst[0], 0 });

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

	if (dst[n * m - 1] == 1e9 + 1) printf("-1");
	else printf("%d", dst[n * m - 1]);

	return 0;
}