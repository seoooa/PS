#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int map[10][10], ans = -1, N, M, block_cnt = 0;
pair<int, int> dxy[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<vector<int>> adj(100);
vector<int> discovered(100, 0);
queue<int> q;
vector<pair<int, int>> virus;
vector<pair<int, int>> start;
vector<int> block(100, 0);

void bfs() {
	while (q.size() > 0) {
		int here = q.front();
		q.pop();

		for (int i = 0; i < adj[here].size(); i++) {
			int next = adj[here][i];

			if (!discovered[next] && !block[next]) {
				q.push(next);
				discovered[next] = 1;
			}
		}
	}
}

void CHECK() {
	for (int i = 0; i < 100; i++) discovered[i] = 0;

	for (int i = 0; i < virus.size(); i++) {
		int start = virus[i].first * M + virus[i].second;

		q.push(start);
		discovered[start] = 1;

		bfs();
	}

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (discovered[i * M + j] == 0) cnt++;
		}
	}

	cnt = cnt - block_cnt - 3;
	ans = max(ans, cnt);
}

int main() {

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];

			if (map[i][j] == 2) virus.push_back({ i, j });
			else if (map[i][j] == 0) start.push_back({ i, j });
			else block_cnt++;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < 4; k++) {
				int nextI = i + dxy[k].first;
				int nextJ = j + dxy[k].second;

				if (nextI >= 0 && nextI < N && nextJ >= 0 && nextJ < M) {
					if (map[nextI][nextJ] == 0) {
						adj[i * M + j].push_back(nextI * M + nextJ);
					}
				}
			}
		}
	}

	for (int i = 0; i < start.size(); i++) {
		for (int j = i + 1; j < start.size(); j++) {
			for (int k = j + 1; k < start.size(); k++) {

				block[start[i].first * M + start[i].second] = 1;
				block[start[j].first * M + start[j].second] = 1;
				block[start[k].first * M + start[k].second] = 1;

				CHECK();
				
				block[start[i].first * M + start[i].second] = 0;
				block[start[j].first * M + start[j].second] = 0;
				block[start[k].first * M + start[k].second] = 0;
			}
		}
	}

	cout << ans << "\n";	

	return 0;
}