#include <iostream>
#include <vector>

using namespace std;

int k, n;
vector<int> S;
vector<int> result;

void CHECK() {
	for (int i = 0; i < result.size(); i++)  cout << result[i] << " ";
	cout << "\n";
}

void f(int x, int y) {
	if (y == 0) {
		CHECK();
		return;
	}

	for (int i = x; i < k; i++) {
		result.push_back(S[i]);
		f(i + 1, y - 1);
		result.pop_back();
	}
}

int main() {

	while (1) {

		cin >> k;
		if (k == 0) break;

		for (int i = 0; i < k; i++) {
			cin >> n;
			S.push_back(n);
		}

		f(0, 6);

		S.clear();
		cout << "\n";
	}

	return 0;
}
