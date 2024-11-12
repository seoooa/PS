#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int arr[100001], dp[100001];
int N;

int DP(int idx) {
	if (idx == 0) return 0;
	if (dp[idx] != -1) return dp[idx];

	int ret;
	ret = max(arr[idx], DP(idx - 1) + arr[idx]);
	dp[idx] = ret;

	return ret;
}

int main() {

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	memset(dp, -1, sizeof(dp));

	DP(N);

	int ans = dp[1];
	for (int i = 1; i <= N; i++) {
		ans = max(ans, dp[i]);
	}

	cout << ans;

	return 0;
}