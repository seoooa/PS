#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

int main() {

	pair<int, int> dxy[4] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
	int map[50][50], dust[50][50];
	queue<int> air;
	int R, C, T, fresher, ans = 0;
	cin >> R >> C >> T;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];

			if (map[i][j] == -1) fresher = i;
		}
	}

	for (int t = 0; t < T; t++) {

		for (int i = 0; i < R; i++) {
			memset(dust[i], 0, sizeof(int) * C);
		}

		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {

				if (map[i][j] > 0) {
					int move = map[i][j] / 5;

					for (int k = 0; k < 4; k++) {
						int nextI = i + dxy[k].first;
						int nextJ = j + dxy[k].second;

						if (nextI < 0 || nextI >= R || nextJ < 0 || nextJ >= C) continue;
						if (map[nextI][nextJ] == -1) continue;

						dust[nextI][nextJ] += move;
						dust[i][j] -= move;
					}
				}
			}
		}

		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				map[i][j] += dust[i][j];
			}
		}

		for (int i = fresher - 2; i >= 0; i--) {
			air.push(map[i][0]);
		}
		for (int j = 1; j < C; j++) {
			air.push(map[0][j]);
		}
		for (int i = 1; i < fresher - 1; i++) {
			air.push(map[i][C - 1]);
		}
		for (int j = C - 1; j > 0; j--) {
			air.push(map[fresher - 1][j]);
		}

		air.pop();
		air.push(0);

		for (int i = fresher - 2; i >= 0; i--) {
			map[i][0] = air.front();
			air.pop();
		}
		for (int j = 1; j < C; j++) {
			map[0][j] = air.front();
			air.pop();
		}
		for (int i = 1; i < fresher - 1; i++) {
			map[i][C - 1] = air.front();
			air.pop();
		}
		for (int j = C - 1; j > 0; j--) {
			map[fresher - 1][j] = air.front();
			air.pop();
		}

		for (int i = fresher + 1; i < R; i++) {
			air.push(map[i][0]);
		}
		for (int j = 1; j < C; j++) {
			air.push(map[R - 1][j]);
		}
		for (int i = R - 2; i >= fresher; i--) {
			air.push(map[i][C - 1]);
		}
		for (int j = C - 2; j > 0; j--) {
			air.push(map[fresher][j]);
		}

		air.pop();
		air.push(0);

		for (int i = fresher + 1; i < R; i++) {
			map[i][0] = air.front();
			air.pop();
		}
		for (int j = 1; j < C; j++) {
			map[R - 1][j] = air.front();
			air.pop();
		}
		for (int i = R - 2; i >= fresher; i--) {
			map[i][C - 1] = air.front();
			air.pop();
		}
		for (int j = C - 2; j > 0; j--) {
			map[fresher][j] = air.front();
			air.pop();
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] > 0) ans += map[i][j];
		}
	}

	cout << ans;

	return 0;
}