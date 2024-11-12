#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	int N, ans = 0;
	long long A[2001];
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	sort(A, A + N);

	for (int t = 0; t < N; t++) {
		int target = A[t];

		int i = 0, j = N - 1;
		
		while (i < j) {
			int sum = A[i] + A[j];

			if (i == t || sum < target) {
				i++;
			}
			else if (j == t || sum > target) {
				j--;
			}
			else {
				ans++;
				break;
			}
		}
	}

	cout << ans;

	return 0;
}