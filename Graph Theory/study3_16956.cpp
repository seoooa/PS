#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj(250001);
char map[501][501];

int main() {

	int R, C, ans = 1;
	cin >> R >> C;

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {

			if (i > 1) adj[(i - 1) * C + j].push_back((i - 2) * C + j);
			if (j > 1) adj[(i - 1) * C + j].push_back((i - 1) * C + j - 1);
			if (j < C) adj[(i - 1) * C + j].push_back((i - 1) * C + j + 1);
			if (i < R) adj[(i - 1) * C + j].push_back(i * C + j);
		}
	}

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (map[i][j] == 'W') {
				for (int v = 0; v < adj[(i - 1) * C + j].size(); v++) {
					int node = adj[(i - 1) * C + j][v];

					if (map[(node - 1) / C + 1][(node - 1) % C + 1] == 'S') {
						ans = 0;
					}
					else if (map[(node - 1) / C + 1][(node - 1) % C + 1] == '.') {
						map[(node - 1) / C + 1][(node - 1) % C + 1] = 'D';
					}
				}
			}
		}
	}

	cout << ans << "\n";

	if (ans) {
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				cout << map[i][j];
			}
			cout << "\n";
		}
	}

	return 0;
}