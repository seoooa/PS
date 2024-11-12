#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int N, ans = 0, sum = 0;
	vector<int> v;

	cin >> N;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;

		v.push_back(a);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < N; i++) {
		sum += v[i];
		ans += sum;
	}

	cout << ans;

	return 0;
}