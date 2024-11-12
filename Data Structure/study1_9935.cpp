#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

	string s1, s2;
	cin >> s1 >> s2;

	vector<pair<char, int>> v;
	int idx = 0;

	for (int i = 0; i < s1.size(); i++) {

		if (s1[i] != s2[idx]) idx = 0;
		if (s1[i] == s2[idx]) idx++;

		v.push_back(make_pair(s1[i], idx));

		if (idx == s2.size()) {
			for (int j = 0; j < s2.size(); j++) v.pop_back();

			if (v.size() == 0) idx = 0;
			else idx = v[v.size() - 1].second;
		}
	}

	if (v.size() == 0) printf("FRULA");
	else {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i].first;
		}
	}

	return 0;
}