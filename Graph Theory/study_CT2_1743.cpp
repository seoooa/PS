#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj(10001);
vector<int> visited(10001, 0);

int map[101][101] = { 0, };
pair<int, int> dxy[4] = { {1, 0}, {-1,0}, {0, 1}, {0, -1} };

int cnt = 0;

void dfs(int here) {
	visited[here] = 1;
	cnt++;

	for (int i = 0; i < adj[here].size(); i++) {
		int next = adj[here][i];

		if (!visited[next]) dfs(next);
	}
}

int main() {

	int N, M, K;
	cin >> N >> M >> K;

	for (int i = 0; i < K; i++) {
		int r, c;
		cin >> r >> c;

		map[r - 1][c - 1] = 1;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < 4; k++) {
				int nextI = i + dxy[k].first;
				int nextJ = j + dxy[k].second;

				if (0 <= nextI && nextI < N && 0 <= nextJ && nextJ < M) {
					if (map[i][j] && map[nextI][nextJ]) {
						adj[i * M + j].push_back(nextI * M + nextJ);
					}
				}
			}
		}
	}

	int max_cnt = 0;
	for (int i = 0; i < N * M; i++) {
		cnt = 0;
		dfs(i);
		
		if (max_cnt < cnt) max_cnt = cnt;
	}

	cout << max_cnt;

	return 0;
}