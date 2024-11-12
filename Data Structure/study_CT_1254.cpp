#include <iostream>

using namespace std;

int main() {

	string S;
	cin >> S;

	int palindrome = 0, ans = 0;
	char last_char = S.back();

	for (int i = 0; i < S.length(); i++) {

		if (S[i] == last_char) {

			int p = i;
			int q = S.length() - 1;

			while (1) {
				if (p >= q) {
					palindrome = 1;
					break;
				}
				else if (S[p] != S[q]) {
					palindrome = 0;
					break;
				}
				p++;
				q--;
			}

			if (palindrome) {
				ans = S.length() + i;
				break;
			}
		}
	}

	if (ans) cout << ans;
	else cout << S.length() * 2 - 1;

	return 0;
}