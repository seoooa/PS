#include <iostream>
#include <vector>
#include <set>

using namespace std;

int N, tmp_sum = 0;
vector<int> S, result;
set<int> sum;

void CHECK() {
	tmp_sum = 0;
	for (int i = 0; i < result.size(); i++) {
		tmp_sum += result[i];
	}
	sum.insert(tmp_sum);;
}

void f(int x, int y) {
	if (y == 0) {
		CHECK();
		return;
	}
	for (int i = x; i < N; i++) {
		result.push_back(S[i]);
		f(i + 1, y - 1);
		result.pop_back();
	}
}

int main() {

	cin >> N;

	int n;
	for (int i = 0; i < N; i++) {
		cin >> n;
		S.push_back(n);
	}
	
	for (int i = 1; i <= N; i++) {
		f(0, i);
	}

	int ans = 1;
	for (auto iter = sum.begin(); iter != sum.end(); iter++) {
		if (ans != *iter) {
			break;
		}
		ans++;
	}

	cout << ans;

	return 0;
}