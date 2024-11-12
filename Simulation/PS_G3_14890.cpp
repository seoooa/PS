#include <iostream>

using namespace std;

int map[101][101];
int N, L, ans = 0;

void CHECK() {
	for (int i = 0; i < N; i++) {
		int cnt = 1;
		int success = 1;
		for (int j = 0; j < N - 1; j++) {
			if (map[i][j] == map[i][j + 1]) {
				cnt++;
			}
			else if (map[i][j] + 1 == map[i][j + 1]) {
				if (cnt < L) success = 0;
				cnt = 1;
			}
			else if (map[i][j] - 1 == map[i][j + 1]) {
				if (j + L > N) success = 0;
				else {
					for (int k = 0; k < L; k++) {
						if (map[i][j + 1] != map[i][j + 1 + k]) success = 0;
					}
				}
				cnt = 0;
				j += (L - 1);
			}
			else success = 0;

			if (!success) break;
		}
		if (success) ans++;
	}
}

int main() {

	cin >> N >> L;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	CHECK();

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			int tmp = map[i][j];
			map[i][j] = map[j][i];
			map[j][i] = tmp;
		}
	}

	CHECK();
	
	cout << ans;

	return 0;
}