#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	string p;
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> p;

		int s = 0, ans = 0, cnt = 0, flag = 0;
		int e = p.length() - 1;

		while (s <= e) {

			if (p[s] != p[e]) {
				if (flag == 0 && p[s] == p[e - 1] && cnt == 0) {
					s++;
					e -= 2;
					cnt = 1;
					continue;
				}
				if (p[s + 1] == p[e] && cnt == 0) {
					s += 2;
					e--;
					cnt = 1;
					continue;
				}

				if (flag == 0 && cnt == 1) {
					flag = 1;
					s = 0;
					e = p.length() - 1;
					cnt = 0;
					continue;
				}

				ans = 2;
				break;
			}

			s++;
			e--;
		}

		if (ans != 2 && cnt == 1) ans = 1;

		cout << ans << endl;
	}

	return 0;
}