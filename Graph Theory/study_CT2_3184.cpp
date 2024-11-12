#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj(62600);
vector<int> sheep;
vector<int> wolf;
vector<int> visited(62600, 0);

int s_cnt = 0, w_cnt = 0;
int s_ans = 0, w_ans = 0;

void dfs(int here) {

	if (!visited[here]) {
		visited[here] = 1;
		
		for (int i = 0; i < sheep.size(); i++) {
			if (sheep[i] == here) s_cnt++;
		}
		for (int i = 0; i < wolf.size(); i++) {
			if (wolf[i] == here) w_cnt++;
		}

		for (int i = 0; i < adj[here].size(); i++) {
			dfs(adj[here][i]);
		}
	}
}

int main() {

	int R, C;
	char map[251][251];

	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];

			if (map[i][j] == 'o') sheep.push_back(i * C + j);
			else if (map[i][j] == 'v') wolf.push_back(i * C + j);
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			
			if (map[i][j] != '#') {
				if (i < R - 1 && map[i + 1][j] != '#') {
					adj[i * C + j].push_back((i + 1) * C + j);
				}
				if (i > 0 && map[i - 1][j] != '#') {
					adj[i * C + j].push_back((i - 1) * C + j);
				}
				if (j < C - 1 && map[i][j + 1] != '#') {
					adj[i * C + j].push_back(i * C + j + 1);
				}
				if (j > 0 && map[i][j - 1] != '#') {
					adj[i * C + j].push_back(i * C + j - 1);
				}
			}
		}
	}


	for (int i = 0; i < R * C; i++) {
		s_cnt = 0; w_cnt = 0;
		
		dfs(i);

		if (s_cnt > w_cnt) s_ans += s_cnt;
		else w_ans += w_cnt;
	}

	cout << s_ans << " " << w_ans;

	return 0;
}