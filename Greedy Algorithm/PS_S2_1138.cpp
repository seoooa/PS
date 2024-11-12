#include <iostream>
#include <vector>

using namespace std;

int main() {

	int N;
	int num[10];
	vector<int> order;
	cin >> N;

	for (int i = 0; i < N; i++) cin >> num[i];

	for (int i = N - 1; i >= 0; i--) {
		
		if (order.size() > num[i]) order.insert(order.begin() + num[i], i + 1);
		else order.push_back(i + 1);
	}

	for (int i = 0; i < N; i++) {
		cout << order[i] << " ";
	}

	return 0;
}