#include <iostream>

using namespace std;

int main() {

	int block[501];
	int H, W, ans = 0, curH = 1;
	cin >> H >> W;

	for (int i = 0; i < W; i++) {
		cin >> block[i];
	}

	while (curH <= H) {
		int startflag = 0;
		int cnt = 0;

		for (int i = 0; i < W; i++) {
			if (curH <= block[i]) {
				if (startflag) {
					ans += cnt;
					cnt = 0;
				}
				else {
					startflag = 1;
					cnt = 0;
				}
			}
			else cnt++;
		}
		curH++;
	}

	cout << ans;

	return 0;
}