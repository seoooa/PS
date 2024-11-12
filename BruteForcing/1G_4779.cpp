#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

void CHECK() {
	printf("-");

	return;
}

void f(int n) {
	if (n == 0) {
		CHECK();
		return;
	}
	f(n - 1);
	for (int i = 0; i < pow(3, n - 1); i++) printf(" ");
	f(n - 1);
}

int main() {

	int N;
	
	while (scanf("%d", &N) != EOF) {
		f(N);
		printf("\n");
	}

	return 0;
}