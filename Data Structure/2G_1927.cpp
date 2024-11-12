#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>

using namespace std;

int main() {

	int N, n;
	priority_queue<int> pq;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &n);

		if (n == 0) {
			if (pq.size() == 0) printf("0\n");
			else {
				printf("%d\n", (-1) * pq.top());
				pq.pop();
			}
		}
		else {
			pq.push((-1) * n);
		}
	}
	return 0;
}