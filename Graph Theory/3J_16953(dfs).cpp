#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<vector<int>> adj(10000);
vector<int> visited(1001, 0);

int A, B, value, cnt = 1, min_cnt = -1, idx = 0;

void dfs(int here) {

	visited[here] = 1;

	if (here != 1) {
		if (here % 2) {
			value = value * 10 + 1;
		}
		else {
			value *= 2;
		}
		cnt++;
	}

	if (value == B) {
		if (min_cnt > cnt || min_cnt == -1) min_cnt = cnt;
	}
	
	if (value > B) {
		if (here % 2) {
			value = (value - 1) / 10;
		}
		else {
			value /= 2;
		}
		cnt--;

		return;
	}

	for (int i = 0; i < adj[here].size(); i++) {
		int next = adj[here][i];
		if (visited[next] == 0) dfs(next);
	}

	if (here % 2) {
		value = (value - 1) / 10;
	}
	else {
		value /= 2;
	}
	cnt--;
}

int main() {
	int depth = 0;
	cin >> A >> B;

	int tmp = A;
	while (tmp < B) {
		tmp *= 2;
		depth++;
	}

	for (int i = 1; i < pow(2, depth); i++) {
		adj[i].push_back(i * 2);
		adj[i].push_back(i * 2 + 1);
	}

	value = A;
	dfs(1);

	cout << min_cnt;
}