#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	
	int T;
	string str;
	vector<int> v;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> str;
		v.clear();

		for (int j = 0; j < str.length(); j++) {
			
			if (str[j] == ')') {
				if (v.size() == 0) {
					v.push_back(str[j]);
					break;
				}
				v.pop_back();
			}
			else v.push_back(str[j]);
		}

		if (v.size() == 0) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}