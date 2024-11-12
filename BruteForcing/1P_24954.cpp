#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

int N;
int cost[20], after_cost[20];
pair<int, int> potion[20][1010];
int result[20];
int r_idx = 0;
int used[20];
int money = 0, min_money = -1;

void CHECK() {

	money = 0;
	
	for (int i = 1; i <= N; i++) {
		after_cost[i] = cost[i];
	}

	for (int i = 0; i < r_idx; i++) {
		int buy = result[i];

		money += after_cost[buy];

		for (int j = 1; j <= potion[buy][0].first; j++){
			after_cost[potion[buy][j].first] -= potion[buy][j].second;

			if (after_cost[potion[buy][j].first] < 1) after_cost[potion[buy][j].first] = 1;
		}
	}

	if (money < min_money || min_money < 0) min_money = money;

	used[result[r_idx - 1]] = 0;
	r_idx--;
}
void f(int y) {

	if (y == 0) {
		CHECK();
		return;
	}

	for (int i = 1; i <= N; i++) {

		while (used[i] == 1) i++;
		if (i > N) break;

		used[i] = 1;
		result[r_idx++] = i;
		f(y - 1);
	}

	used[result[r_idx - 1]] = 0;
	r_idx--;

	return;
}

int main() {

	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &cost[i]);
	}

	for (int i = 1; i <= N; i++) {
		scanf("%d", &potion[i][0].first);

		for (int j = 1; j <= potion[i][0].first; j++) {
			scanf("%d %d", &potion[i][j].first, &potion[i][j].second);
		}
	}

	for (int i = 1; i <= N; i++) used[i] = 0;

	f(N);

	printf("%d", min_money);

	return 0;
}