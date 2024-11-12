#include <iostream>
#include <vector>

using namespace std;

int N, M, ans = -1;
char board[25][25];

vector<int> result;
vector<int> button;
vector<pair<int, int>> coin;

void CHECK() {
	int coin1_i = coin[0].first;
	int coin1_j = coin[0].second;
	int coin2_i = coin[1].first;
	int coin2_j = coin[1].second;

	int out = 0;

	for (int i = 0; i < result.size(); i++) {
		switch (result[i]) {
		case 0:
			if (board[coin1_i][coin1_j - 1] != '#') coin1_j -= 1;
			if (board[coin2_i][coin2_j - 1] != '#') coin2_j -= 1;

			break;
		case 1:
			if (board[coin1_i][coin1_j + 1] != '#') coin1_j += 1;
			if (board[coin2_i][coin2_j + 1] != '#') coin2_j += 1;
			break;
		case 2:
			if (board[coin1_i - 1][coin1_j] != '#') coin1_i -= 1;
			if (board[coin2_i - 1][coin2_j] != '#') coin2_i -= 1;
			break;
		case 3:
			if (board[coin1_i + 1][coin1_j] != '#') coin1_i += 1;
			if (board[coin2_i + 1][coin2_j] != '#') coin2_i += 1;
			break;
		}

		if (coin1_i < 0 || coin1_i >= N) out++;
		if (coin1_j < 0 || coin1_j >= M) out++;
		if (coin2_i < 0 || coin2_i >= N) out++;
		if (coin2_j < 0 || coin2_j >= M) out++;

		if (out == 1) {
			ans = i + 1;
			break;
		}
	}
	return;
}

void f(int x, int y) {
	if (y == 0) {
		CHECK();
		return;
	}
	for (int i = x; i < button.size(); i++) {
		result.push_back(button[i]);
		f(0, y - 1);
		result.pop_back();
	}
}


int main() {

	for (int i = 0; i < 4; i++) {
		button.push_back(i);
	}

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];

			if (board[i][j] == 'o') {
				coin.push_back(make_pair(i, j));
			}
		}
	}

	for (int i = 1; i <= 10; i++) {
		f(0, i);

		if (ans != -1) break;
	}

	cout << ans;

	return 0;
}