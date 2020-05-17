#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const int INF = 1e8;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<string> S(5);
    for (auto &s : S) cin >> s;

    // 0 -> R, 1 -> B, 2 -> W
    vector<vector<int> > C(N, vector<int>(3, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 5; ++j) {
            switch (S.at(j).at(i)) {
                case 'R':
                    C.at(i).at(0)++;
                    break;
                case 'B':
                    C.at(i).at(1)++;
                    break;
                case 'W':
                    C.at(i).at(2)++;
                    break;
                default:
                    break;
            }
        }
    }

    vector<vector<int> > dp(N, vector<int>(3, INF));
    for (int j = 0; j < 3; ++j) {
        dp.at(0).at(j) = 5 - C.at(0).at(j);
    }
    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < 3; ++j) {
            dp.at(i).at(j) = min(dp.at(i - 1).at((j + 1) % 3), dp.at(i - 1).at((j + 2) % 3)) + (5 - C.at(i).at(j));
        }
    }

    int ans = min(dp.at(N - 1).at(0), min(dp.at(N - 1).at(1), dp.at(N - 1).at(2)));
    cout << ans << endl;

    return 0;
}