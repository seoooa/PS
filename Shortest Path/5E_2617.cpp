#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> adj(101, vector<int>(101, 1e9 + 1));
vector<vector<int>> dst;

int main() {

	int n, m;
	scanf("%d%d", &n, &m);

	int a, b;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		adj[a][b] = 1;
	}

	dst = adj;

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dst[i][j] = min(dst[i][j], dst[i][k] + dst[k][j]);
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (dst[i][j] != 1e9 + 1) cnt++;
		}
		if (cnt > n / 2) ans++;
	}

	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (dst[j][i] != 1e9 + 1) cnt++;
		}
		if (cnt > n / 2) ans++;
	}

	printf("%d", ans);

	return 0;
}