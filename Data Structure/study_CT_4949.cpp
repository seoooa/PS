#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

	char c;
	int ans;
	vector<char> stk;

	while (1) {
		string str;
		getline(cin, str);

		if (str == ".") break;

		stk.clear();
		ans = 1;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '(' || str[i] == '[') stk.push_back(str[i]);
			else if (str[i] == ')') {
				if (stk.size() == 0 || stk.back() != '(') {
					ans = 0;
					break;
				}
				else {
					stk.pop_back();
				}
			}
			else if (str[i] == ']') {
				if (stk.size() == 0 || stk.back() != '[') {
					ans = 0;
					break;
				}
				else {
					stk.pop_back();
				}
			}
		}

		if (stk.size() > 0) ans = 0;

		if (ans) cout << "yes\n";
		else cout << "no\n";
	}

	return 0;
}