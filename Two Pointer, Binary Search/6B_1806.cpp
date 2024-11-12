#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	vector<int> v;
	int N, S;
	cin >> N >> S;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	int ans = 1e9 + 1;
	int sum = 0, e = 0;
	for (int s = 0; s < N; s++) {
		while (sum < S && e < N) {
			sum += v[e];
			e++;
		}

		if (sum >= S) {
			ans = min(ans, e - s);
			sum -= v[s];
		}
	}

	if (ans == 1e9 + 1) cout << 0;
	else cout << ans;

	return 0;
}