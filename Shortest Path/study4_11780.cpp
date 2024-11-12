#include <iostream>
#include <vector>

using namespace std;

constexpr int INF = 1e9 + 1;

vector<vector<int>> adj(101, vector<int>(101, INF));
vector<vector<int>> dst;
vector<int> path[101][101];

int main() {

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		if (c < adj[a][b]) {
			adj[a][b] = c;
			path[a][b].clear();
			path[a][b].push_back(a);
			path[a][b].push_back(b);
		}
	}

	dst = adj;

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dst[i][k] + dst[k][j] < dst[i][j]) {
					path[i][j] = path[i][k];
					path[i][j].insert(path[i][j].end(), path[k][j].begin() + 1, path[k][j].end());
					
					dst[i][j] = dst[i][k] + dst[k][j];
				}
			}
		}
	}

	// dst 출력
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dst[i][j] == INF || i == j) cout << 0 << " ";
			else cout << dst[i][j] << " ";
		}
		cout << "\n";
	}

	// 경로 출력
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dst[i][j] == INF || i == j) cout << 0;
			else {
				int city_num = path[i][j].size();
				cout << city_num << " ";
				for (int c = 0; c < city_num; c++) cout << path[i][j][c] << " ";
			}

			cout << "\n";
		}
	}

	return 0;
}