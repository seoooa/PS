#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> order;

int main() {

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int p;
		cin >> p;

		order.push_back(p);
	}

	sort(order.begin(), order.end());

	int time = 0, sum = 0;
	for (int i = 0; i < order.size(); i++) {
		time += order[i];
		sum += time;
	}

	cout << sum;

	return 0;
}