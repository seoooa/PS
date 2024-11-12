#include <iostream>
#include <queue>

using namespace std;

int main() {

	int N, K, n = 1;
	cin >> N >> K;

	queue<int> q;
	for (int i = 1; i <= N; i++) q.push(i);

	if (q.size() == 1) {
		cout << "<" << q.front() << ">";
		q.pop();
	}
	while (q.size() != 0) {
		int tmp = q.front();
		q.pop();

		if (n % K == 0) {
			if (n == K) cout << "<" << tmp << ", ";
			else if (q.size() == 0) cout << tmp << ">";
			else cout << tmp << ", ";
		}
		else q.push(tmp);

		n++;
	}

	return 0;
}