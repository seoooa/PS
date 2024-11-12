#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {

	int T, idx1, idx2;
	string str;
	char c;
	vector<char> v;

	cin >> T;
	cin.ignore();

	for (int i = 0; i < T; i++) {

		getline(cin, str);

		v.clear();
		idx1 = 0;

		for (int j = 0; j < str.length(); j++) {
			c = str[j];

			v.push_back(c);

			if (c == ' ') {
				idx2 = j;
				reverse(v.begin() + idx1, v.begin() + idx2);
				idx1 = idx2 + 1;
			}
			else if (j == str.length() - 1) {
				idx2 = j;
				reverse(v.begin() + idx1, v.end());
				idx1 = idx2 + 1;
			}
		}

		for (int j = 0; j < v.size(); j++) cout << v[j];
		cout << endl;
	}

	return 0;
}