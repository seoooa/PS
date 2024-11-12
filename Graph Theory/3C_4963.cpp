#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj(2501);
vector<int> visited(2501, 0);
int dx[8] = { 0, -1, 0, 1, -1, -1, 1, 1 };
int dy[8] = { 1, 0, -1, 0, 1, -1, 1, -1 };

void dfs(int here) {

	visited[here] = 1;

	for (int i = 0; i < adj[here].size(); i++) {
		int next = adj[here][i];
		if (visited[next] == 0) dfs(next);
	}
}

int main() {

	int W, H, n, cnt;

	while (1) {

		cin >> W >> H;
		if (W == 0 && H == 0) break;

		for (int i = 1; i <= 2500; i++) adj[i].clear();
		for (int i = 1; i <= 50; i++) {
			for (int j = 1; j <= 50; j++) {
				visited[(i - 1) * W + j] = 0;
			}
		}
		cnt = 0;
		vector<vector<int>> map(H + 1, vector<int>(W + 1));

		for (int i = 1; i <= H; i++) {
			for (int j = 1; j <= W; j++) {

				cin >> n;
				map[i][j] = n;

				for (int k = 0; k < 8; k++) {
					int ni = i + dy[k];
					int nj = j + dx[k];

					if (ni > H || nj > W || ni < 1 || nj < 1) continue;

					if (map[i][j]) {
						adj[(i - 1) * W + j].push_back((ni - 1) * W + nj);
					}
				}
			}
		}

		for (int i = 1; i <= H; i++) {
			for (int j = 1; j <= W; j++) {
				if (visited[(i - 1) * W + j] == 0 && map[i][j] == 1) {
					cnt++;
					dfs((i - 1) * W + j);
				}
			}
		}

		cout << cnt << endl;
	}

	return 0;
}