#include <iostream>
#include <vector>

using namespace std;

pair<int, int> dxy[4] = { {1, 0}, {0, -1}, {-1, 0}, {0, 1} };

int main() {

	int N, ans = 0;
	int map[101][101];
	vector<int> dragon;

	cin >> N;

	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			map[i][j] = 0;
		}
	}

	for (int i = 0; i < N; i++) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;

		dragon.clear();
		dragon.push_back(d);

		for (int j = 0; j < g; j++) {
			int size = dragon.size();

			for (int k = size - 1; k >= 0; k--) {
				int tmpD = (dragon[k] + 1) % 4;

				dragon.push_back(tmpD);
			}
		}

		map[y][x] = 1;
		for (int k = 0; k < dragon.size(); k++) {
			y += dxy[dragon[k]].second;
			x += dxy[dragon[k]].first;

			map[y][x] = 1;
		}
	}

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (map[i][j] && map[i + 1][j] && map[i][j + 1] && map[i + 1][j + 1]) {
				ans++;
			}
		}
	}

	cout << ans;

	return 0;
}