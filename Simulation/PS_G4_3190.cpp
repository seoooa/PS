#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

int main() {

	int map[101][101];
	pair<int, int> dxy[4] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
	int N, K, L, ans = 0;
	int time = 0, dir = 1;
	int currI = 1, currJ = 1;
	queue<pair<int, int>> snake;

	cin >> N >> K;

	for (int i = 0; i <= N; i++) {
		memset(map[i], 0, sizeof(int) * (N + 1));
	}

	snake.push({ 1, 1 });
	map[1][1] = 1;

	for (int i = 0; i < K; i++) {
		int a, b;
		cin >> a >> b;
		map[a][b] = 2;
	}

	cin >> L;

	for (int i = 0; i < L; i++) {
		int X, nextI, nextJ;
		char C;
		cin >> X >> C;

		if (!ans) {
			while (1) {
				time++;

				nextI = currI + dxy[dir].first;
				nextJ = currJ + dxy[dir].second;

				if (nextI < 1 || nextI > N || nextJ < 1 || nextJ > N) {
					ans = time;
					break;
				}

				if (map[nextI][nextJ] == 1) {
					ans = time;
					break;
				}
				else if (map[nextI][nextJ] == 2) {
					snake.push({ nextI, nextJ });
					map[nextI][nextJ] = 1;
				}
				else {
					int tmpI = snake.front().first;
					int tmpJ = snake.front().second;
					snake.pop();
					map[tmpI][tmpJ] = 0;

					snake.push({ nextI, nextJ });
					map[nextI][nextJ] = 1;
				}

				currI = nextI;
				currJ = nextJ;

				if (time == X) {
					switch (C) {
					case 'L':
						dir--;
						if (dir < 0) dir += 4;
						break;
					case 'D':
						dir++;
						dir %= 4;
						break;
					}
					break;
				}

			}
		}
	}

	if (!ans) {
		while (1) {
			time++;

			int nextI = currI + dxy[dir].first;
			int nextJ = currJ + dxy[dir].second;

			if (nextI < 1 || nextI > N || nextJ < 1 || nextJ > N) {
				ans = time;
				break;
			}

			if (map[nextI][nextJ] == 1) {
				ans = time;
				break;
			}
			else if (map[nextI][nextJ] == 2) {
				snake.push({ nextI, nextJ });
				map[nextI][nextJ] = 1;
			}
			else {
				int tmpI = snake.front().first;
				int tmpJ = snake.front().second;
				snake.pop();
				map[tmpI][tmpJ] = 0;

				snake.push({ nextI, nextJ });
				map[nextI][nextJ] = 1;
			}

			currI = nextI;
			currJ = nextJ;
		}
	}
	
	cout << ans;

	return 0;
}