#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int A[51][51], B[51][51], C[51][51];

int main() {

	int N, M, ans = 0;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char c;
			cin >> c;
			A[i][j] = int(c) - 48;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char c;
			cin >> c;
			B[i][j] = int(c) - 48;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			C[i][j] = abs(A[i][j] - B[i][j]);
		}
	}

	for (int i = 0; i < N - 2; i++) {
		for (int j = 0; j < M - 2; j++) {

			if (C[i][j]) {
				for (int p = i; p < i + 3; p++) {
					for (int q = j; q < j + 3; q++) {
						C[p][q] -= 1;
						C[p][q] = abs(C[p][q]);
					}
				}
				ans++;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (C[i][j]) ans = -1;
		}
	}

	cout << ans;

	return 0;
}