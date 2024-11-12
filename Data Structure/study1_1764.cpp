#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {

	int N, M, cnt = 0;
	string name;
	map<string, int> m;

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N + M; i++) {
		cin >> name;

		if (m[name]) cnt++;
		m[name]++;
	}

	printf("%d\n", cnt);
	for (auto iter = m.begin(); iter != m.end(); iter++) {
		if (iter->second == 2) cout << iter->first << endl;
	}

	return 0;
}