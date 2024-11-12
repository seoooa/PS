#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N;
int mat[5000][5000];
int result[10];

void CHECK(int value) {
	result[value + 1]++;
}

void f(int length, int row, int col) {
	int allsame = 1;

	for (int i = row; i < row + length; i++) {
		for (int j = col; j < col + length; j++) {
			if (mat[i][j] != mat[row][col]) {
				allsame = 0;
				break;
			}
		}
		if (!allsame) break;
	}

	if (allsame) {
		CHECK(mat[row][col]);
		return;
	}

	length /= 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			f(length, row + length * i, col + length * j);
		}
	}
}

int main() {

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &mat[i][j]);
		}
	}

	for (int i = 0; i < 10; i++) result[i] = 0;

	f(N, 0, 0);

	for (int i = 0; i < 3; i++) printf("%d\n", result[i]);

	return 0;
}