#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

static bool cmp(pair<string, int> a, pair<string, int> b) {
	if (a.second == b.second) return a.first < b.first;
	else return a.second > b.second;
}

int main() {

	int N;
	char title[100];
	map<string, int> m;

	cin >> N;
	for (int i = 0; i < N; i++) {

		cin >> title;
		if (m.find(title) != m.end()) {
			m[title]++;
		}
		else {
			m.insert(make_pair(title, 1));
		}
	}

	vector<pair<string, int>> v(m.begin(), m.end());

	sort(v.begin(), v.end(), cmp);

	cout << v.begin()->first;

	return 0;
}