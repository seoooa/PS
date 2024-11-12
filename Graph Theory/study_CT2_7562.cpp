#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> adj(90001);
vector<int> discovered(90001, 0);
vector<int> dst(90001, 0);
queue<int> q;

void bfs() {

	while (q.size() > 0) {
		int here = q.front();
		q.pop();

		for (int i = 0; i < adj[here].size(); i++) {
			int next = adj[here][i];

			if (!discovered[next]) {
				discovered[next] = 1;
				q.push(next);

				dst[next] = dst[here] + 1;
			}
		}
	}
}

int main() {

	pair<int, int> dxy[8] = { {1, 2}, {2, 1}, {-1, 2}, {2, -1}, {1, -2}, { -2, 1}, { -1, -2}, { -2, -1} };

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int l, ai, aj, bi, bj;

		cin >> l;
		cin >> ai >> aj;
		cin >> bi >> bj;

		for (int i = 0; i < adj.size(); i++) {
			adj[i].clear();
			discovered[i] = 0;
			dst[i] = 0;
		}

		for (int i = 0; i < l; i++) {
			for (int j = 0; j < l; j++) {

				for (int k = 0; k < 8; k++) {
					int ni = i + dxy[k].first;
					int nj = j + dxy[k].second;

					if (ni >= 0 && ni < l && nj >= 0 && nj < l) {
						adj[i * l + j].push_back(ni * l + nj);
					}
				}
			}
		}

		q.push(ai * l + aj);
		discovered[ai * l + aj] = 1;
		dst[ai * l + aj] = 0;

		bfs();

		cout << dst[bi * l + bj] << "\n";
	}

	return 0;
}