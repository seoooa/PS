#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	vector<int> v;
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	int ptr = 0, cnt = 0;
	for (int i = N - 1; i >= 0; i--) {
		while (ptr < i && v[i] + v[ptr] < M) ptr++;
		if (i <= ptr) break;
		cnt++; ptr++;
	}

	cout << cnt;

	return 0;
}