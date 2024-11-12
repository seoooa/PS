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

	int a, b, c;
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &a, &b, &c);

		adj[a][b] = min(adj[a][b], c);
	}
	
	dst = adj;

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dst[i][j] = min(dst[i][j], dst[i][k] + dst[k][j]);
			}
		}
	}

	for (int i = 0; i <= n; i++) dst[i][i] = 1e9 + 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dst[i][j] == 1e9 + 1) printf("0 ");
			else printf("%d ", dst[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}