#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int arr[1001][3], dp[1001][3];

int DP(int idx, int color) {
	if (idx == 0) return 0;
	if (dp[idx][color] != -1) return dp[idx][color];
	
	int ret = int(1e9);
	for (int i = 0; i < 3; i++) {
		if (i != color) {
			ret = min(ret, DP(idx - 1, i) + arr[idx][color]);
		}
	}

	dp[idx][color] = ret;
	return ret;
}

int main() {

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}

	memset(dp, -1, sizeof(dp));

	int ans = int(1e9);
	for (int i = 0; i < 3; i++) {
		ans = min(ans, DP(N, i));
	}

	cout << ans;

	return 0;
}