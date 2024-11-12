#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int N, op_cnt[5], ans, min_ans = INT_MAX, max_ans = INT_MIN;
vector<int> A, result;
vector<pair<int, int>> op;

void CHECK() {

	ans = A[0];

	for (int i = 0; i < result.size(); i++) {
		switch (result[i]){
		case 0:
			ans += A[i + 1];
			break;
		case 1:
			ans -= A[i + 1];
			break;
		case 2:
			ans *= A[i + 1];
			break;
		case 3:
			ans /= A[i + 1];
			break;
		}
	}

	if (ans < min_ans) min_ans = ans;
	if (ans > max_ans) max_ans = ans;

	return;
}

void f(int x, int y) {
	if (y == 0) {
		CHECK();
		return;
	}

	for (int i = 0; i < N - 1; i++) {
		if (op[i].second) continue;

		op[i].second = 1;
		result.push_back(op[i].first);
		f(0, y - 1);
		op[i].second = 0;
		result.pop_back();
	}
}

int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;

		A.push_back(n);
	}

	for (int i = 0; i < 4; i++) {
		cin >> op_cnt[i];

		for (int j = 0; j < op_cnt[i]; j++) {
			op.push_back(make_pair(i, 0));
		}
	}

	f(0, N - 1);

	cout << max_ans << "\n" << min_ans;

	return 0;
}