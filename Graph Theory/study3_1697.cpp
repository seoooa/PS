#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> adj(100001);
vector<int> discovered(100001, 0);
vector<int> dst(100001, 0);
queue<int> q;

int N, K;

void bfs() {
	while (q.size() > 0) {
		int here = q.front();
		q.pop();

		if (here == K) return;

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

	for (int i = 0; i <= 100000; i++) {
		if (i - 1 >= 0) adj[i].push_back(i - 1);
		if (i + 1 <= 100000) adj[i].push_back(i + 1);
		if (2 * i <= 100000 && i != 0) adj[i].push_back(2 * i);
	}

	cin >> N >> K;

	q.push(N);
	bfs();

	cout << dst[K];

	return 0;
}