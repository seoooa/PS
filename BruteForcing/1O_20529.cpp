#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** mbti;
int N, r_idx, t_idx;
int result[10];
int three[10];
int dist;
int min_dist;

void CHECK() {

	for (int i = 0; i < 4; i++) {
		if (mbti[result[0]][i] != mbti[result[1]][i]) dist++;
	}

	r_idx--;
}

void g(int x, int y) {

	if (y == 0) {
		CHECK();
		return;
	}

	for (int i = x; i < 3; i++) {
		result[r_idx++] = three[i];
		g(i + 1, y - 1);
	}

	r_idx--;
}

void f(int x, int y) {

	if (min_dist == 0) return;

	if (y == 0) {

		t_idx--;
		dist = 0;
		r_idx = 0;

		g(0, 2);

		if (min_dist < 0 || dist < min_dist) min_dist = dist;
		return;
	}

	for (int i = x; i < N; i++) {
		three[t_idx++] = i;
		f(i + 1, y - 1);
	}

	t_idx--;
}

int main() {

	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		scanf("%d", &N);

		mbti = (char**)malloc(sizeof(char*) * N);
		for (int j = 0; j < N; j++) {
			mbti[j] = (char*)malloc(sizeof(char) * 4);
		}

		for (int j = 0; j < N; j++) {
			scanf("%s", mbti[j]);
		}

		r_idx = 0;
		t_idx = 0;
		min_dist = -1;
		
		f(0, 3);

		printf("%d\n", min_dist);
	}


	return 0;
}