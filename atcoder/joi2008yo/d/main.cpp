#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int M;
    cin >> M;
    vector<int> X(M), Y(M);
    for (int i = 0; i < M; ++i) {
        cin >> X.at(i) >> Y.at(i);
    }
    int N;
    cin >> N;
    vector<int> SX(N), SY(N);
    for (int i = 0; i < N; ++i) {
        cin >> SX.at(i) >> SY.at(i);
    }

    for (int i = 0; i < N; ++i) {
        int dx = SX.at(i) - X.at(0);
        int dy = SY.at(i) - Y.at(0);
        bool can = true;
        for (int j = 0; j < M; ++j) {
            int nx = X.at(j) + dx;
            int ny = Y.at(j) + dy;
            if (find(SX.begin(), SX.end(), nx) == SX.end()) {
                can = false;
                break;
            }
            if (find(SY.begin(), SY.end(), ny) == SY.end()) {
                can = false;
                break;
            }
        }
        if (can) {
            cout << dx << ' ' << dy << endl;
            exit(0);
        }
    }

    return 0;
}