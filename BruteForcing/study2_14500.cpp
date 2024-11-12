#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int N, M, max_t = -1;
	int paper[501][501];
	int tetro1[10][10] = { 0 };
	int tetro2[10][10] = { 0 };
	vector<pair<int, int>> v;

	cin >> N >> M;

	tetro1[1][5] = 1;
	tetro1[5][1] = 1;
	tetro1[2][4] = 1;
	tetro1[4][2] = 1;
	tetro1[2][6] = 1;
	tetro1[6][2] = 1;
	tetro1[3][5] = 1;
	tetro1[5][3] = 1;
	tetro1[2][5] = 1;
	tetro1[5][2] = 1;

	tetro2[1][4] = 1;
	tetro2[4][1] = 1;
	tetro2[2][3] = 1;
	tetro2[3][2] = 1;
	tetro2[3][6] = 1;
	tetro2[6][3] = 1;
	tetro2[4][5] = 1;
	tetro2[5][4] = 1;
	tetro2[3][4] = 1;
	tetro2[4][3] = 1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> paper[i][j];
		}
	}

	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < M - 2; j++) {

			int tmp_sum = 0;
			for (int p = 0; p < 2; p++) {
				for (int q = 0; q < 3; q++) {

					v.push_back(make_pair(paper[i + p][j + q], p * 3 + q + 1));

					tmp_sum += paper[i + p][j + q];
					sort(v.begin(), v.end());
				}
			}

			for (int k = 0; k < 6; k++) {
				for (int s = k + 1; s < 6; s++) {
					if (tetro1[v[k].second][v[s].second]) continue;
					else {
						tmp_sum -= v[k].first;
						tmp_sum -= v[s].first;

						if (max_t <= tmp_sum) max_t = tmp_sum;

						tmp_sum += v[k].first;
						tmp_sum += v[s].first;
					}
				}
			}

			v.clear();
		}
	}

	for (int i = 0; i < N - 2; i++) {
		for (int j = 0; j < M - 1; j++) {

			int tmp_sum = 0;
			for (int p = 0; p < 3; p++) {
				for (int q = 0; q < 2; q++) {

					v.push_back(make_pair(paper[i + p][j + q], p * 2 + q + 1));

					tmp_sum += paper[i + p][j + q];
					sort(v.begin(), v.end());
				}
			}

			for (int k = 0; k < 6; k++) {
				for (int s = k + 1; s < 6; s++) {
					if (tetro2[v[k].second][v[s].second]) continue;
					else {
						tmp_sum -= v[k].first;
						tmp_sum -= v[s].first;

						if (max_t <= tmp_sum) max_t = tmp_sum;

						tmp_sum += v[k].first;
						tmp_sum += v[s].first;
					}
				}
			}

			v.clear();
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M - 3; j++) {

			int tmp_sum = 0;
			for (int k = 0; k < 4; k++) {
				tmp_sum += paper[i][j + k];
			}

			if (max_t <= tmp_sum) max_t = tmp_sum;
		}
	}

	for (int j = 0; j < M; j++) {
		for (int i = 0; i < N - 3; i++) {

			int tmp_sum = 0;
			for (int k = 0; k < 4; k++) {
				tmp_sum += paper[i + k][j];
			}

			if (max_t <= tmp_sum) max_t = tmp_sum;
		}
	}

	cout << max_t;

	return 0;
}