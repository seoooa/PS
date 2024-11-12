#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

vector<pair<int, int>> people(100);
vector<int> cnt(100, 0);
int N;
int r_idx = 0;
int result[1000];

void CHECK() {

	if (people[result[0]].first > people[result[1]].first && people[result[0]].second > people[result[1]].second) {
		cnt[result[1]]++;
	}
	else if (people[result[0]].first < people[result[1]].first && people[result[0]].second < people[result[1]].second) {
		cnt[result[0]]++;
	}

	r_idx -= 1;
}

void f(int x, int y) {
	if (y == 0) {
		CHECK();
		return;
	}
	for (int i = x; i < N; i++) {
		result[r_idx++] = i;
		f(i + 1, y - 1);
	}

	r_idx -= 1;
}

int main() {

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &people[i].first, &people[i].second);
	}

	f(0, 2);

	for (int i = 0; i < N; i++) printf("%d ", cnt[i]+1);

	return 0;
}