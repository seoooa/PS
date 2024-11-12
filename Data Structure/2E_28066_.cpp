#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>

using namespace std;

int main() {

	int N, K, ans;
	queue<int> que;
	scanf("%d %d", &N, &K);

	for (int i = 1; i <= N; i++) que.push(i);

	while (que.size() > 0) {
		if (que.size() < K) {
			ans = que.front();
			break;
		}
		else {
			que.push(que.front());
			que.pop();
			for (int i = 0; i < K - 1; i++) que.pop();
		}
	}

	printf("%d", ans);

	return 0;
}