#include <iostream>
#include <queue>

using namespace std;

int main() {

	int N, M, ans = 0;
	cin >> N >> M;

	queue<int> q;

	for (int i = 1; i <= N; i++) {
		q.push(i);
	}

	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;

		if (q.front() == num) {
			q.pop();
		}
		else {
			int cnt = 0;
			while (1) {
				if (q.front() == num) {
					q.pop();
					break;
				}

				int tmp = q.front();
				q.pop();
				q.push(tmp);
				cnt++;
			}

			if (q.size() + 1 - cnt >= cnt) ans += cnt;
			else ans += q.size() + 1 - cnt;
		}
	}

	cout << ans;

	return 0;
}