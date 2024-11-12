#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <set>

using namespace std;

int main() {
	
	int n, m, cnt = 0;
	char str[550];
	set<string> s;

	scanf("%d %d",&n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", str);
		s.insert(str);
	}

	for (int i = 0; i < m; i++) {
		scanf("%s", str);
		if (s.find(str) != s.end()) cnt++;
	}

	printf("%d", cnt);
}