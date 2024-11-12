#include <iostream>
#include <vector>

using namespace std;

vector<int> coin;

int main() {

	int N, K, ans = 0;
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		int m;
		cin >> m;

		coin.push_back(m);
	}

	for (int i = N - 1; i >= 0; i--) {
		while (1) {
			if (coin[i] > K) break;

			K -= coin[i];
			ans++;
		}
	}

	cout << ans;

	return 0;
}