#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> adj(10001);
pair<int, int> dxy[4] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
vector<int> discovered(10001, 0);
vector<int> dst(10001, -1);
queue<int> q;

void bfs() {
	while (q.size() > 0) {
		int here = q.front();
		q.pop();

		for (int i = 0; i < adj[here].size(); i++) {
			int next = adj[here][i];

			if (!discovered[next]) {
				q.push(next);
				discovered[next] = 1;

				dst[next] = dst[here] + 1;
			}
		}
	}
}

int main() {

	int N, M;
	int map[101][101];
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char c;
			cin >> c;
			map[i][j] = (int)c - 48;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < 4; k++) {
				int nextI = i + dxy[k].first;
				int nextJ = j + dxy[k].second;

				if (nextI >= 0 && nextI < N && nextJ >= 0 && nextJ < M) {
					if (map[nextI][nextJ]) adj[i * M + j].push_back(nextI * M + nextJ);
				}
			}
		}
	}

	q.push(0);
	discovered[0] = 1;
	dst[0] = 1;

	bfs();

	cout << dst[N * M - 1];

	return 0;
}