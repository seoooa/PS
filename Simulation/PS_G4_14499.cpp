#include <iostream>

using namespace std;

int main() {

	int N, M, x, y, K;
	int map[20][20];
	int dice[6] = { 0, 0, 0, 0, 0, 0 };
	cin >> N >> M >> x >> y >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < K; i++) {
		int order;
		cin >> order;

		int tmp = dice[0];
		switch (order) {
		case 1:
			if (y + 1 == M) continue;
			y++;
			dice[0] = dice[2];
			dice[2] = dice[5];
			dice[5] = dice[1];
			dice[1] = tmp;
			break;
		case 2:
			if (y - 1 == -1) continue;
			y--;
			dice[0] = dice[1];
			dice[1] = dice[5];
			dice[5] = dice[2];
			dice[2] = tmp;
			break;
		case 3:
			if (x - 1 == -1) continue;
			x--;
			dice[0] = dice[4];
			dice[4] = dice[5];
			dice[5] = dice[3];
			dice[3] = tmp;
			break;
		case 4:
			if (x + 1 == N) continue;
			x++;
			dice[0] = dice[3];
			dice[3] = dice[5];
			dice[5] = dice[4];
			dice[4] = tmp;
			break;
		}

		if (map[x][y] == 0) map[x][y] = dice[5];
		else {
			dice[5] = map[x][y];
			map[x][y] = 0;
		}

		cout << dice[0] << "\n";
	}

	return 0;
}