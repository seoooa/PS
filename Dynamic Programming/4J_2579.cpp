#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int arr[301], dp[301];

int DP(int idx) {
	if (idx <= 0) return 0;
	if (dp[idx] != -1) return dp[idx];

	int	ret = max(DP(idx - 2) + arr[idx], DP(idx - 3) + arr[idx - 1] + arr[idx]);
	dp[idx] = ret;

	return ret;
}

int main() {

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	memset(dp, -1, sizeof(dp));
	dp[1] = arr[1];

	DP(N);
	
	cout << dp[N];

	return 0;
}