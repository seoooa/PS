#include <iostream>
#include <string.h>

using namespace std;

int dp[11];

int DP(int x) {

	if (dp[x] != -1) return dp[x];

	int ret = DP(x - 3) + DP(x - 2) + DP(x - 1);
	dp[x] = ret;

	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	dp[1] = 1; dp[2] = 2; dp[3] = 4;

	int T, n;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> n;

		cout << DP(n) << "\n";
	}

	return 0;
}