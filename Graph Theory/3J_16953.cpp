#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

map<long long, int> dst;
queue<long long> q;

long long A, B, min_dst = -1;

void bfs() {
	while (q.size() > 0) {
		long long here = q.front();
		q.pop();

		long long n1 = here * 2;
		long long n2 = here * 10 + 1;

		if (n1 <= B) {
			q.push(n1);
			dst[n1] = dst[here] + 1;
		}
		if (n2 <= B) {
			q.push(n2);
			dst[n2] = dst[here] + 1;
		}

		if (n1 == B) {
			if (min_dst == -1 || min_dst > dst[n1]) min_dst = dst[n1];
		}
		if (n2 == B) {
			if (min_dst == -1 || min_dst > dst[n2]) min_dst = dst[n2];
		}

	}
}

int main() {

	cin >> A >> B;

	q.push(A);
	dst[A] = 0;
	bfs();

	if (min_dst != -1) cout << min_dst + 1;
	else cout << min_dst;

	return 0;
}