#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int N, max_weight = -1;
	cin >> N;

	vector<int> rope;

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;

		rope.push_back(-n);
	}

	sort(rope.begin(), rope.end());

	for (int i = 0; i < rope.size(); i++) {
		int weight = -rope[i] * (i + 1);

		if (max_weight <= weight) max_weight = weight;
	}

	cout << max_weight;

	return 0;
}