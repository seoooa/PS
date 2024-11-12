#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stack>

using namespace std;

int main() {

	int N, n;
	char order[100];
	stack<int> stk;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%s", order);

		if (!strcmp(order, "push")) {
			scanf("%d", &n);
			stk.push(n);
		}
		else if (!strcmp(order, "pop")) {
			if (stk.size() == 0) printf("-1\n");
			else {
				printf("%d\n", stk.top());
				stk.pop();
			}
		}
		else if (!strcmp(order, "size")) {
			printf("%d\n", stk.size());
		}
		else if (!strcmp(order, "empty")) {
			if (stk.empty()) printf("1\n");
			else printf("0\n");
		}
		else if (!strcmp(order, "top")) {
			if (stk.size() == 0) printf("-1\n");
			else {
				printf("%d\n", stk.top());
			}
		}
	}
	return 0;
}