#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	vector<int> v;
	int N, K;
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	vector<int> cnt(200001, 0);

	int s = 0, ans = 0;
	for (int e = 0; e < N; e++) {
		cnt[v[e]]++;

		if (cnt[v[e]] > K) {

			while (v[s] != v[e]) {
				cnt[v[s]]--;
				s++;
			}

			cnt[v[s]]--;
			s++;
		}
		ans = max(ans, e - s + 1);
	}

	printf("%d",ans);

	return 0;
}