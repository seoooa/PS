#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N, M;
int r_idx = 0;
int result[1000];

void CHECK() {
	for (int i = 0; i < r_idx; i++) printf("%d ", result[i]);
	printf("\n");

	r_idx -= 1;
}

void f(int x, int y) {
	if (y == 0) {
		CHECK();
		return;
	}
	for (int i = x; i <= N; i++) {
		result[r_idx++] = i;
		f(i + 1, y - 1);
	}

	r_idx -= 1;
}

int main() {
	scanf("%d %d", &N, &M);
	f(1, M);

	return 0;
}