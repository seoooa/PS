#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> adj(1000);
vector<int> visited(1000, 0);
int cnt;

void dfs(int here) {

	if (!visited[here]) {
		visited[here] = 1;
		cnt++;

		for (int i = 0; i < adj[here].size(); i++) {
			dfs(adj[here][i]);
		}
	}
}

int main() {

	int N;
	char map[30][30];
	vector<int> house_cnt;

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == '1') {
				if (i - 1 >= 0 && map[i - 1][j] == '1') adj[i * N + j + 1].push_back((i - 1) * N + j + 1);
				if (i + 1 < N && map[i + 1][j] == '1') adj[i * N + j + 1].push_back((i + 1) * N + j + 1);
				if (j - 1 >= 0 && map[i][j - 1] == '1') adj[i * N + j + 1].push_back(i * N + j);
				if (j + 1 < N && map[i][j + 1] == '1') adj[i * N + j + 1].push_back(i * N + j + 2);
			}
		}
	}

	for (int i = 1; i <= N * N; i++) {
		if (!visited[i] && map[(i - 1) / N][(i - 1) % N] == '1') {
			cnt = 0;
			dfs(i);
			house_cnt.push_back(cnt);
		}
	}

	cout << house_cnt.size() << "\n";
	sort(house_cnt.begin(), house_cnt.end());
	for (int i = 0; i < house_cnt.size(); i++) cout << house_cnt[i] << "\n";

	return 0;
}