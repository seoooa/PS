#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

int main() {

	int N, n;
	char order[100];
	deque<int> dq;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%s", order);

		if (!strcmp(order, "push_front")) {
			scanf("%d", &n);
			dq.push_front(n);
		}
		else if (!strcmp(order, "push_back")) {
			scanf("%d", &n);
			dq.push_back(n);
		}
		else if (!strcmp(order, "pop_front")) {
			if (dq.size() == 0) printf("-1\n");
			else {
				printf("%d\n", dq.front());
				dq.pop_front();
			}
		}
		else if (!strcmp(order, "pop_back")) {
			if (dq.size() == 0) printf("-1\n");
			else {
				printf("%d\n", dq.back());
				dq.pop_back();
			}
		}
		else if (!strcmp(order, "size")) {
			printf("%d\n", dq.size());
		}
		else if (!strcmp(order, "empty")) {
			if (dq.empty()) printf("1\n");
			else printf("0\n");
		}
		else if (!strcmp(order, "front")) {
			if (dq.size() == 0) printf("-1\n");
			else {
				printf("%d\n", dq.front());
			}
		}
		else if (!strcmp(order, "back")) {
			if (dq.size() == 0) printf("-1\n");
			else {
				printf("%d\n", dq.back());
			}
		}
	}
	return 0;
}