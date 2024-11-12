#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int N, L, tape = 0;
	float curr = 0;
	cin >> N >> L;

	vector<int> loc;

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;

		loc.push_back(n);
	}

	sort(loc.begin(), loc.end());

	for (int i = 0; i < loc.size(); i++) {
		
		if (loc[i] > curr) {
			curr = (loc[i] + L - 0.5);
			tape++;
		}
	}

	cout << tape;

	return 0;
}