#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> adj(1000001);
vector<int> discovered(1000001, 0);
vector<int> dst(1000001, -1);
vector<int> parent(1000001, -1);
vector<int> path;
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
				parent[next] = here;
			}
		}
	}
}

int main() {

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		if (!(i % 3)) adj[i].push_back(i / 3);
		if (!(i % 2)) adj[i].push_back(i / 2);
		if (i - 1 >= 1) adj[i].push_back(i - 1);
	}

	discovered[N] = 1;
	dst[N] = 0;
	q.push(N);

	bfs();

	int node = 1;
	while (node != N) {
		path.push_back(node);
		node = parent[node];
	}
	path.push_back(N);

	cout << dst[1] << "\n";
	for (int i = path.size() - 1; i >= 0; i--) cout << path[i] << " ";

	return 0;
}