#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

int main() {

	int N, n;
	char order[100];
	queue<int> que;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%s", order);

		if (!strcmp(order, "push")) {
			scanf("%d", &n);
			que.push(n);
		}
		else if (!strcmp(order, "pop")) {
			if (que.size() == 0) printf("-1\n");
			else {
				printf("%d\n", que.front());
				que.pop();
			}
		}
		else if (!strcmp(order, "size")) {
			printf("%d\n", que.size());
		}
		else if (!strcmp(order, "empty")) {
			if (que.empty()) printf("1\n");
			else printf("0\n");
		}
		else if (!strcmp(order, "front")) {
			if (que.size() == 0) printf("-1\n");
			else {
				printf("%d\n", que.front());
			}
		}
		else if (!strcmp(order, "back")) {
			if (que.size() == 0) printf("-1\n");
			else {
				printf("%d\n", que.back());
			}
		}
	}
	return 0;
}