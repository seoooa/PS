#include <iostream>

using namespace std;

int main() {

	int N, K, cnt = 0, clap = 0;
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;

		if (a <= clap && clap <= a + K) continue;
		else {
			clap = a + K;
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}