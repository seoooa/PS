#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N, M;
int r_idx = 0;
int result[1000];
int card[1000];
int max_s = 0;

void CHECK() {
	int sum = 0;

	for (int i = 0; i < r_idx; i++) {
		sum += card[result[i]];
	}

	if (sum <= M && sum > max_s) {
		max_s = sum;
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
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%d", &card[i]);
	}

	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N - i - 1; j++) {
			if (card[j] > card[j + 1]) {
				int tmp = card[j];
				card[j] = card[j + 1];
				card[j + 1] = tmp;
			}
		}
	}

	f(0, 3);

	printf("%d\n", max_s);

	return 0;
}