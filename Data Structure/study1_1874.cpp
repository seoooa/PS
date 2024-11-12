#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

int main() {

	int N, n, i = 1;
	stack<int> stk;
	vector<char> result;

	cin >> N;

	while (1) {

		if (i > N + 1 || (i == N + 1 && stk.size() == 0)) break;

		if (stk.size() == 0) {
			stk.push(i++);
			result.push_back('+');
		}

		cin >> n;

		while (1) {
			if (stk.top() == n) {
				stk.pop();
				result.push_back('-');
				break;
			}
			else {
				stk.push(i++);
				result.push_back('+');

				if (i > N + 1) break;
			}
		}
	}

	for (int i = 0; i < stk.size(); i++) {
		cin >> n;
		if (stk.top() == n) {
			stk.pop();
			result.push_back('-');
		}
		else {
			cout << "NO" << endl;
			break;
		}
	}

	if (stk.size() == 0) {
		for (int i = 0; i < result.size(); i++) cout << result[i] << "\n";
	}

	return 0;
}