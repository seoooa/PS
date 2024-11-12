#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int N, height, v_index = 0, ans = 0;
	cin >> N;

	vector<pair<int, int>> v;
	vector<pair<int, int>> left;

	for (int i = 0; i < N; i++) {
		int L, H;
		cin >> L >> H;
		v.push_back({ L, H });
	}

	sort(v.begin(), v.end());

	height = v[v_index].second;
	for (int i = v[0].first; i <= v[v.size() - 1].first; i++) {

		if (i == v[v_index].first) {

			left.clear();
			for (int j = v_index; j < v.size(); j++) {
				left.push_back({ -v[j].second, v[j].first });
			}
			sort(left.begin(), left.end());

			if (v[v_index].first == left.front().second) {
				ans += v[v_index].second;
				if (left.size() > 1) height = -left[1].first;
			}
			else {
				height = max(height, v[v_index].second);
				ans += height;
			}

			v_index++;
		}
		else {
			ans += height;
		}
	}

	cout << ans;

	return 0;
}