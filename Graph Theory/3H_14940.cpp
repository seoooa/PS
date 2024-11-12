#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> adj(1000001);
vector<int> discovered(1000001, 0);
vector<int> dst(1000001, -1);
queue<int> q;

vector<vector<int>> map(1001, vector<int>(1001));

int dx[4] = { -1, 1, 0, 0};
int dy[4] = { 0, 0, -1, 1};

void bfs() {
	while (q.size() > 0) {
		int here = q.front();
		q.pop();

		for (int i = 0; i < adj[here].size(); i++) {
			int next = adj[here][i];

			if (discovered[next] == 0) {
				q.push(next);
				discovered[next] = 1;
				dst[next] = dst[here] + 1;
			}
		}
	}
}

int main() {

	int N, M, start_i, start_j;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];

			if (map[i][j] == 0) dst[(i - 1) * M + j] = 0;
			if (map[i][j] == 2) {
				start_i = i;
				start_j = j;
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {

			if (map[i][j] > 0) {
				for (int k = 0; k < 4; k++) {
					int ni = i + dy[k];
					int nj = j + dx[k];

					if (ni > N || nj > M || ni < 1 || nj < 1) continue;

					if (map[ni][nj] > 0) adj[(i - 1) * M + j].push_back((ni - 1) * M + nj);
				}
			}
		}
	}

	q.push((start_i - 1) * M + start_j);
	discovered[(start_i - 1) * M + start_j] = 1;
	dst[(start_i - 1) * M + start_j] = 0;

	bfs();

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cout << dst[(i - 1) * M + j] << " ";
		}
		cout << endl;
	}

	return 0;
}