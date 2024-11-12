#include <iostream>

using namespace std;

int N;
int row_same_cnt = 1, row_max = -1;
int col_same_cnt = 1, col_max = -1;
int max_candy = -1;
char candy[55][55];

void CHECK(int x, int y) {
	
	row_same_cnt = 1; col_same_cnt = 1;
	row_max = -1; col_max = -1;

	for (int j = 1; j < N; j++) {
		if (candy[x][j] == candy[x][j - 1]) {
			row_same_cnt++;
			if (row_max <= row_same_cnt) row_max = row_same_cnt;
		}
		else row_same_cnt = 1;
	}
	row_same_cnt = 1;
	if (x < N - 1) {
		for (int j = 1; j < N; j++) {
			if (candy[x + 1][j] == candy[x + 1][j - 1]) {
				row_same_cnt++;
				if (row_max <= row_same_cnt) row_max = row_same_cnt;
			}
			else row_same_cnt = 1;
		}
	}

	for (int i = 1; i < N; i++) {
		if (candy[i][y] == candy[i - 1][y]) {
			col_same_cnt++;
			if (col_max <= col_same_cnt) col_max = col_same_cnt;
		}
		else col_same_cnt = 1;
	}

	col_same_cnt = 1;
	if (y < N - 1) {
		for (int i = 1; i < N; i++) {
			if (candy[i][y + 1] == candy[i - 1][y + 1]) {
				col_same_cnt++;
				if (col_max <= col_same_cnt) col_max = col_same_cnt;
			}
			else col_same_cnt = 1;
		}
	}

	if (max_candy <= row_max) max_candy = row_max;
	if (max_candy <= col_max) max_candy = col_max;
}

int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> candy[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1; j++) {
			char tmp;

			tmp = candy[i][j];
			candy[i][j] = candy[i][j + 1];
			candy[i][j + 1] = tmp;

			CHECK(i, j);

			tmp = candy[i][j];
			candy[i][j] = candy[i][j + 1];
			candy[i][j + 1] = tmp;
		}
	}

	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N - 1; i++) {
			char tmp;

			tmp = candy[i][j];
			candy[i][j] = candy[i + 1][j];
			candy[i + 1][j] = tmp;

			CHECK(i, j);

			tmp = candy[i][j];
			candy[i][j] = candy[i + 1][j];
			candy[i + 1][j] = tmp;
		}
	}

	cout << max_candy;

	return 0;
}