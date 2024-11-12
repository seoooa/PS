#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	string str;
	vector<char> v;
	int idx1 = 0, idx2 = 0;
	int tag = -1;

	getline(cin, str);

	for (int i = 0; i < str.length(); i++) {
		v.push_back(str[i]);

		if (str[i] == '<') tag = 1;
		else if (tag && str[i] == '>') {
			idx1 = idx2 + 1;
			tag = 0;
		}
		
		if ((tag != 1 && str[i] == ' ') || (tag != -1 && str[i] == '<')) {
			reverse(v.begin() + idx1, v.begin() + idx2);
			idx1 = idx2 + 1;
		}
		
		if (i == str.length() - 1) reverse(v.begin() + idx1, v.begin() + idx2 + 1);

		idx2++;
	}

	for (int i = 0; i < v.size(); i++) cout << v[i];

	return 0;
}