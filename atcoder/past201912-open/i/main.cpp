#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e18;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    vector<ll> S(M, 0);
    vector<ll> C(M);
    for (int i = 0; i < M; ++i) {
        string s;
        cin >> s >> C.at(i);
        for (int x = 0; x < N; ++x) {
            if (s.at(x) == 'Y') {
                S.at(i) |= (1 << x);
            }
        }
    }
    vector<ll> dp(1 << N, INF);
    dp.at(0) = 0;
    for (int i = 0; i < (1 << N); ++i) {
        for (int j = 0; j < M; ++j) {
            dp.at(i | S.at(j)) = min(dp.at(i | S.at(j)), dp.at(i) + C.at(j));
        }
    }
    ll ans = dp.at((1 << N) - 1);
    cout << ((ans == INF) ? -1 : ans) << endl;

    return 0;
}