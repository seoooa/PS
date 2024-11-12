#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int>  b) {
	if (a.second != b.second) return a.second < b.second;
	else return a.first < b.first;
}

int main() {

	int N, curr_time = 0, cnt = 0;
	vector<pair<int, int>> v;

	cin >>  N;
	for (int i = 0; i < N; i++) {
		int s, e;
		cin >> s >> e;
		v.push_back({ s, e });
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < N; i++) {
		if (curr_time <= v[i].first) {
			curr_time = v[i].second;
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}