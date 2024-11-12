#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N, S;
int num[50];
int r_idx = 0;
int result[1000];
int cnt = 0, sum =  0;

void CHECK() {
	cnt++;
}

void f(int x, int y) {

	if (sum == S && y != N) {
		CHECK();
	}

	if (y == 0) {
		sum -= num[result[r_idx - 1]];
		r_idx--;
		return;
	}

	for (int i = x; i < N; i++) {
		sum += num[i];
		result[r_idx++] = i;
		f(i + 1, y - 1);
	}

	sum -= num[result[r_idx - 1]];
	r_idx--;
}

int main() {

	scanf("%d %d", &N, &S);
	for (int i = 0; i < N; i++) scanf("%d", &num[i]);

	f(0, N);

	printf("%d", cnt);

	return 0;
}