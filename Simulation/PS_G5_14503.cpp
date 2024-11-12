#include <iostream>

using namespace std;

int main() {

	int map[50][50], clean[50][50], ans = 0;
	pair<int, int> dxy[4] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
	int N, M, r, c, d;
	cin >> N >> M >> r >> c >> d;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			clean[i][j] = 0;
		}
	}

	while (1) {

		if (!clean[r][c]) {
			ans++;
			clean[r][c] = 1;
		}
		
		int cFlag = 0;
		for (int i = 0; i < 4; i++) {
			int nextR = r + dxy[i].first;
			int nextC = c + dxy[i].second;

			if (map[nextR][nextC]) continue;

			if (!clean[nextR][nextC]) cFlag = 1;
		}

		if (cFlag) {
			d = (d + 3) % 4;

			int nextR = r + dxy[d].first;
			int nextC = c + dxy[d].second;

			if (!clean[nextR][nextC] && !map[nextR][nextC]) {
				r = nextR;
				c = nextC;
			}
		}
		else {
			int nextR = r + dxy[(d + 2) % 4].first;
			int nextC = c + dxy[(d + 2) % 4].second;

			if (map[nextR][nextC]) break;

			r = nextR;
			c = nextC;
		}
	}

	cout << ans;

	return 0;
}