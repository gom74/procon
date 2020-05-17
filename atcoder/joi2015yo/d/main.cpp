#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    vector<int> D(N);
    for (auto &x : D) cin >> x;
    vector<int> C(M);
    for (auto &x : C) cin >> x;

    vector<vector<ll> > dp(M + 1, vector<ll>(N + 1, LLONG_MAX));
    for (int i = 0; i <= M; ++i) {
        dp.at(i).at(0) = 0;
    }
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (dp.at(i).at(j) == LLONG_MAX) {
                dp.at(i + 1).at(j + 1) = dp.at(i).at(j + 1);
            } else {
                dp.at(i + 1).at(j + 1) = min(dp.at(i).at(j + 1), dp.at(i).at(j) + 1LL * C.at(i) * D.at(j));
            }
        }
    }

    cout << dp.at(M).at(N) << endl;

    return 0;
}