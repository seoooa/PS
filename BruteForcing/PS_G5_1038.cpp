#include <iostream>
#include <vector>

using namespace std;

vector<int> result;
int num[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
int ans = -1, N;

void CHECK() {
	ans++;

	if (ans == N) {
		for (int i = 0; i < result.size(); i++) {
			cout << result[i];
		}
	}
}

void f(int x, int y) {
	if (ans == N) return;
	if (y == 0) {
		CHECK();
		return;
	}

	for (int i = 0; i <= x; i++) {
		result.push_back(num[i]);
		f(i - 1, y - 1);
		result.pop_back();
	}

}

int main() {
	cin >> N;

	if (N > 1022) {
		cout << -1;
		return 0;
	}
	
	for (int sz = 1; sz <= 10; sz++) {
		for (int i = 0; i < 10; i++) {
			result.push_back(num[i]);
			f(i - 1, sz - 1);
			result.pop_back();
		}
	}

	return 0;
}