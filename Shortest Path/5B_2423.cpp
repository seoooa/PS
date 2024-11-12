#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<pair<int, int>>> adj(300000);
priority_queue<pair<int, int>> pq;
vector<int> dst(300000, 1e9 + 1);

int main() {

	int N, M;
	scanf("%d %d", &N, &M);
	getchar();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char a;
			scanf("%c", &a);

			if (a == '\\') {
				//printf("i: %d j: %d connect %d %d weight 0\n",i,j, i * (M + 1) + j, (i + 1) * (M + 1) + j + 1);
				adj[i * (M + 1) + j].push_back({ (i + 1) * (M + 1) + j + 1, 0 });
				adj[i * (M + 1) + j + 1].push_back({ (i + 1) * (M + 1) + j, 1 });

				//printf("i: %d j: %d connect %d %d weight 1\n", i, j, i * (M + 1) + j + 1, (i + 1) * (M + 1) + j);

				adj[(i + 1) * (M + 1) + j + 1].push_back({ i * (M + 1) + j, 0 });
				adj[(i + 1) * (M + 1) + j].push_back({ i * (M + 1) + j + 1, 1 });
			}
			else if (a == '/') {
				//printf("i: %d j: %d connect %d %d\n",i,j, i * (M + 1) + j, (i + 1) * (M + 1) + j + 1);
				adj[i * (M + 1) + j].push_back({ (i + 1) * (M + 1) + j + 1, 1 });
				adj[i * (M + 1) + j + 1].push_back({ (i + 1) * (M + 1) + j, 0 });

				adj[(i + 1) * (M + 1) + j + 1].push_back({ i * (M + 1) + j, 1 });
				adj[(i + 1) * (M + 1) + j].push_back({ i * (M + 1) + j + 1, 0 });
			}
		}
		getchar();
	}

	//printf("size: %d\n", adj[7].size());
	for (int i = 0; i < adj[7].size(); i++) {
		//printf("connect 7 %d , weight: %d\n", adj[7][i].first, adj[7][i].second);
	}

	for (int i = 0; i < adj[0].size(); i++) {
		dst[adj[0][i].first] = adj[0][i].second;
		pq.push({ (-1) * adj[0][i].second, adj[0][i].first });
	}
	dst[0] = 0;

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
				pq.push({(-1) * ndst, next});
			}
		}
	}

	if (dst[(N + 1) * (M + 1) - 1] == 1e9 + 1) printf("NO SOLUTION");
	else printf("%d", dst[(N + 1) * (M + 1) - 1]);

	return 0;
}