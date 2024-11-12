#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>

using namespace std;

int main() {
	queue<pair<int, int>> que;

	int T, N, M, imp, idx, order, ans;
	int imp_arr[150];

	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		scanf("%d %d", &N, &M);

		for (int j = 0; j < N; j++) {
			scanf("%d", &imp);
			imp_arr[j] = imp;
			que.push(make_pair(j, imp));
		}

		for (int j = 0; j < N - 1; j++) {
			for (int k = 0; k < N - j - 1; k++) {
				if (imp_arr[k] < imp_arr[k + 1]) {
					int tmp = imp_arr[k];
					imp_arr[k] = imp_arr[k + 1];
					imp_arr[k + 1] = tmp;
				}
			}
		}

		idx = 0;
		order = 1;
		while (que.size() > 0) {
			if (que.front().second == imp_arr[idx]) {
				if (que.front().first == M) ans = order;

				que.pop();
				order++;
				idx++;
			}
			else {
				que.push(make_pair(que.front().first, que.front().second));
				que.pop();
			}
		}
		printf("%d\n", ans);
	}
}