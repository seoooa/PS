#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int TC;
	scanf("%d", &TC);

	for (int t = 0; t < TC; t++) {

		vector<vector<int>> adj(501, vector<int>(501, 1e9 + 1));
		vector<vector<int>> dst;

		int N, M, W;
		scanf("%d%d%d", &N, &M, &W);

		for (int i = 0; i < M; i++) {
			int S, E, T;
			scanf("%d%d%d", &S, &E, &T);

			adj[S][E] = min(adj[S][E], T);
			adj[E][S] = min(adj[E][S], T);
		}

		for (int i = 0; i < W; i++) {
			int S, E, T;
			scanf("%d%d%d", &S, &E, &T);

			adj[S][E] = min(adj[S][E], -T);
		}

		dst = adj;

		for (int k = 1; k <= N; k++) {
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= N; j++) {
					dst[i][j] = min(dst[i][j], dst[i][k] + dst[k][j]);
				}
			}
		}

		int cycle = 0;
		for (int i = 0; i <= N; i++) {
			if (dst[i][i] < 0) {
				cycle = 1;
				break;
			};
		}

		if (cycle) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}