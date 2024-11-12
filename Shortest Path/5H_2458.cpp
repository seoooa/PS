#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> adj(501, vector<int>(501, 1e9 + 1));
vector<vector<int>> dst;

int main() {

	int N, M;
	scanf("%d%d", &N, &M);

	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d%d", &a, &b);

		adj[a][b] = 1;
	}

	dst = adj;

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				dst[i][j] = min(dst[i][j], dst[i][k] + dst[k][j]);
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		int cnt = 0;

		for (int j = 1; j <= N; j++) {
			if (dst[i][j] != 1e9 + 1) cnt++;
			if (dst[j][i] != 1e9 + 1) cnt++;
		}

		if (cnt == N - 1) ans++;
	}

	printf("%d", ans);

	return 0;
}