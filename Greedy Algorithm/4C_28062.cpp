#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int N, ans = 0, tmp = 0;
	vector<int> v;

	cin >> N;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;

		v.push_back(a);
	}

	sort(v.begin(), v.end(), greater<int>());

	for (int i = 0; i < N; i++) {
		
		if (v[i] % 2) {
			tmp += v[i];
			if (tmp % 2 == 0) {
				ans += tmp;
				tmp = 0;
			}
		}
		else ans += v[i];
	}

	cout << ans;

	return 0;
}