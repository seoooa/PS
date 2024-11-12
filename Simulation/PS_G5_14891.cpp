#include <iostream>
#include <math.h>

using namespace std;

int main() {

	int K, ans = 0;
	int wheel[5][8];
	int top[5] = { 0, 0, 0, 0, 0 };
	int copy[5] = { 0, 0, 0, 0, 0 };

	for (int i = 1; i <= 4; i++) {
		for (int j = 0; j < 8; j++) {
			
			char c;
			cin >> c;

			wheel[i][j] = (int)(c - 48);
		}
	}

	cin >> K;

	for (int i = 0; i < K; i++) {
		int num, dir, first_dir;
		cin >> num >> dir;
		dir *= -1;

		copy[num] += (dir + 8);
		copy[num] %= 8;
		dir *= -1;

		first_dir = dir;

		for (int cur = num; cur >= 2; cur--) {
			if (wheel[cur][(top[cur] + 6) % 8] == wheel[cur - 1][(top[cur - 1] + 2) % 8]) break;

			if (wheel[cur][(top[cur] + 6) % 8] != wheel[cur - 1][(top[cur - 1] + 2) % 8]) {
				copy[cur - 1] += (dir + 8);
				copy[cur - 1] %= 8;
				dir *= -1;
			}
		}
		

		dir = first_dir;

		for (int cur = num; cur <= 3; cur++) {
			if (wheel[cur][(top[cur] + 2) % 8] == wheel[cur + 1][(top[cur + 1] + 6) % 8]) break;

			if (wheel[cur][(top[cur] + 2) % 8] != wheel[cur + 1][(top[cur + 1] + 6) % 8]) {
				copy[cur + 1] += (dir + 8);
				copy[cur + 1] %= 8;
				dir *= -1;
			}
		}

		for (int j = 1; j <= 4; j++) top[j] = copy[j];
	}

	for (int i = 1; i <= 4; i++) {
		if (wheel[i][top[i]]) ans += pow(2, i - 1);
	}

	cout << ans;

	return 0;
}