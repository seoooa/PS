#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N;
int r_idx = 0;
int result[1000];
int used[10];

void CHECK() {
	for (int i = 0; i < r_idx; i++) printf("%d ", result[i]);
	printf("\n");

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
}

int main() {

	scanf("%d", &N);

	for (int i = 1; i <= N; i++) used[i] = 0;

	f(N);

	return 0;
}