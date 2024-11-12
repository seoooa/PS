#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>

using namespace std;

int main() {

	int N, A, present;
	priority_queue<int> pq;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A);

		if (A == 0) {
			if (pq.size() == 0) printf("-1\n");
			else {
				printf("%d\n", pq.top());
				pq.pop();
			}
		}
		else {
			for (int j = 0; j < A; j++) {
				scanf("%d", &present);
				pq.push(present);
			}
		}
	}
	return 0;
}