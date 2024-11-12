#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, cnt = 0, bad_cnt = 0;
vector<int> result;
int bad[210][210] = { 0 };

void CHECK() {
    cnt++;
    
    if (bad[result[0]][result[1]] || bad[result[0]][result[2]] || bad[result[1]][result[2]]) cnt--;
}

void f(int x, int y) {
    if (y == 0) {
        CHECK();
        return;
    }
    for (int i = x; i <= N; i++) {
        result.push_back(i);
        f(i + 1, y - 1);
        result.pop_back();
    }
}

int main() {

    int n1, n2;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        cin >> n1 >> n2;

        bad[n1][n2] = 1;
        bad[n2][n1] = 1;
    }

    f(1, 3);

    cout << cnt;

    return 0;
}