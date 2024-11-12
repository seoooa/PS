#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main() {

	string str;
	deque <char> dq;
	int M, start = 0;
	char order, tmp;

	cin >> str;

	for (int i = 0; i < str.length(); i++) dq.push_back(str[i]);

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> order;

		switch (order)
		{
		case 'L':
			if (start != dq.size()) {
				tmp = dq.back();
				dq.pop_back();
				dq.push_front(tmp);

				start++;
			}
			break;
		case 'D':
			if (start != 0) {
				tmp = dq.front();
				dq.pop_front();
				dq.push_back(tmp);

				start--;
			}
			break;
		case 'B':
			if (start != dq.size()) {
				dq.pop_back();
			}
			break;
		case 'P':
			cin >> tmp;
			dq.push_back(tmp);

			break;
		default:
			break;
		}
	}

	for (int i = 0; i < start; i++) {
		tmp = dq.front();
		dq.pop_front();
		dq.push_back(tmp);
	}

	while (dq.size() > 0) {
		cout << dq.front();
		dq.pop_front();
	}

	return 0;
}