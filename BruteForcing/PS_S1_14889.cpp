#include <iostream>
#include <vector>

using namespace std;

int N, ans = -1;
int S[20][20];
int link[20];
vector<int> start;

void CHECK() {

	int start_sum = 0;
	for (int i = 0; i < start.size(); i++) {
		for (int j = i + 1; j < start.size(); j++) {
			start_sum += (S[start[i]][start[j]] + S[start[j]][start[i]]);
		}
	}

	int link_sum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (link[i] && link[j]) link_sum += (S[i][j] + S[j][i]);
		}
	}

	if (ans < 0) ans = abs(start_sum - link_sum);
	else ans = min(ans, abs(start_sum - link_sum));
}

void f(int x, int y) {

	if (y == 0) {
		CHECK();
	}

	for (int i = x; i < N; i++) {
		start.push_back(i);
		link[i] = 0;

		f(i + 1, y - 1);

		start.pop_back();
		link[i] = 1;
	}
}

int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {

		link[i] = 1;
		for (int j = 0; j < N; j++) {
			cin >> S[i][j];
		}
	}

	f(0, N / 2);

	cout << ans;

	return 0;
}
