#include <iostream>
#include <vector>

using namespace std;

vector<int> bulb_A;
vector<int> bulb_B;
vector<int> bulb_tmp;

int main() {

	int N, ans1 = 0, ans2 = 0;;
	cin >> N;

	for (int i = 0; i < N; i++) {
		char n;
		cin >> n;

		bulb_A.push_back((int)n - 48);
	}
	bulb_tmp = bulb_A;

	for (int i = 0; i < N; i++) {
		char n;
		cin >> n;

		bulb_B.push_back((int)n - 48);
	}

	for (int i = 0; i < N - 2; i++) {

		if (bulb_A[i] != bulb_B[i]) {

			bulb_A[i] = abs(bulb_A[i] - 1);
			bulb_A[i + 1] = abs(bulb_A[i + 1] - 1);
			bulb_A[i + 2] = abs(bulb_A[i + 2] - 1);

			ans1++;
		}
	}

	if (bulb_A[N - 2] != bulb_B[N - 2] || bulb_A[N - 1] != bulb_B[N - 1]) {
		bulb_A[N - 2] = abs(bulb_A[N - 2] - 1);
		bulb_A[N - 1] = abs(bulb_A[N - 1] - 1);

		ans1++;
	}

	for (int i = 0; i < N; i++) {
		if (bulb_A[i] != bulb_B[i]) {
			ans1 = -1;
			break;
		}
	}

	bulb_A = bulb_tmp;

	bulb_A[0] = abs(bulb_A[0] - 1);
	bulb_A[1] = abs(bulb_A[1] - 1);
	ans2++;
	
	for (int i = 0; i < N - 2; i++) {

		if (bulb_A[i] != bulb_B[i]) {

			bulb_A[i] = abs(bulb_A[i] - 1);
			bulb_A[i + 1] = abs(bulb_A[i + 1] - 1);
			bulb_A[i + 2] = abs(bulb_A[i + 2] - 1);

			ans2++;
		}
	}

	if (bulb_A[N - 2] != bulb_B[N - 2] || bulb_A[N - 1] != bulb_B[N - 1]) {
		bulb_A[N - 2] = abs(bulb_A[N - 2] - 1);
		bulb_A[N - 1] = abs(bulb_A[N - 1] - 1);

		ans2++;
	}

	for (int i = 0; i < N; i++) {
		if (bulb_A[i] != bulb_B[i]) {
			ans2 = -1;
			break;
		}
	}

	if (ans1 == -1) ans1 = ans2;
	if (ans2 == -1) ans2 = ans1;

	cout << min(ans1, ans2);

	return 0;
}