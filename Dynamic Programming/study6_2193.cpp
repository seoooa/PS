#include <iostream>
#include <string.h>

using namespace std;

int N;
long long dp[100][2];

long long DP(int idx, int num) {
	if (idx == 1) return 1;
	if (dp[idx][num] != -1) return dp[idx][num];

	long long ret = 0;

	for (int nn = 0; nn < 2; nn++) {
		if (num && nn) continue;
		ret += DP(idx - 1, nn);
	}

	dp[idx][num] = ret;

	return ret;
}

int main() {

	cin >> N;

	memset(dp, -1, sizeof(dp));

	cout << DP(N, 1);

	return 0;
}


/*
dp[1] = 1; 1
dp[2] = 1; 10
dp[3] = 2; 101, 100
dp[4] = 3; 1010, 1001, 1000
dp[5] = 5; 10100, 10101, 10010, 10001, 10000
dp[6] = 8; 101000, 101001, 101010, 100101 100100, 100010, 100001, 100000
*/