#include <iostream>
#include <vector>

using namespace std;

int N, M, min_dist = -1, dist_sum = 0;
int map[2510][2510] = { 0 };
vector<pair<int, int>> store;
vector<pair<int, int>> house;
vector<int> dist[100][100];
vector<int> result;

void CHECK() {

	dist_sum = 0;

	for (int i = 0; i < house.size(); i++) {
		int tmp_min = 200;
		int curr_dist;
		for (int j = 0; j < M; j++) {

			curr_dist = dist[house[i].first][house[i].second][result[j] - 1];

			if (tmp_min >= curr_dist) tmp_min = curr_dist;
		}
		dist_sum += tmp_min;
	}

	if (min_dist == -1 || min_dist >= dist_sum) min_dist = dist_sum;
}

void f(int x, int y) {
	if (y == 0) {
		CHECK();
		return;
	}

	for (int i = x; i <= store.size(); i++) {
		result.push_back(i);
		f(i + 1, y - 1);
		result.pop_back();
	}
}

int main() {

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) store.push_back(make_pair(i, j));
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {

			if (map[i][j] == 1) {
				house.push_back(make_pair(i, j));

				for (int k = 0; k < store.size(); k++) {
					int dist_tmp = abs(i - store[k].first) + abs(j - store[k].second);
					dist[i][j].push_back(dist_tmp);
				}
			}
		}
	}

	f(1, M);

	cout << min_dist;

	return 0;
}