#include <iostream>

using namespace std;

int main() {

	int N, M, size, ans = 0;
	cin >> N >> M;

	int mat[51][51];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char c;
			cin >> c;

			mat[i][j] = (int)c - 48;
		}
	}

	size = min(N, M);

	while (1) {
		if (size == 1 || ans) break;

		for (int i = 0; i < N - size + 1; i++) {
			for (int j = 0; j < M - size + 1; j++) {
				int p1 = mat[i][j];
				int p2 = mat[i + size - 1][j];
				int p3 = mat[i][j + size - 1];
				int p4 = mat[i + size - 1][j + size - 1];

				if (p1 == p2 && p2 == p3 && p3 == p4) {
					ans = size * size;
					break;
				}
			}
		}

		size--;
	}

	if (ans) cout << ans;
	else cout << 1;

	return 0;
}