#include <iostream>
#include <vector>

using namespace std;

constexpr int INF = 1e9 + 1;

vector<vector<int>> adj(110, vector<int>(110, INF));
vector<vector<int>> dst;

int main() {
	
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int w;
			cin >> w;

			if (w) adj[i][j] = w;
			//if (i == j) adj[i][j] = 1;
		}
	}

	dst = adj;

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				dst[i][j] = min(dst[i][j], dst[i][k] + dst[k][j]);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (dst[i][j] == INF) cout << 0 << " ";
			else cout << 1 << " ";
		}
		cout << "\n";
	}

	return 0;
}