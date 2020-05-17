#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    while (true) {
        int N, M;
        cin >> N >> M;
        if (N == 0 && M == 0) break;
        vector<int> C(M), x(N);
        for (auto &c : C) cin >> c;
        for (auto &p : x) cin >> p;

        vector<vector<ll> > dp(N + 1, vector<ll>(256, LLONG_MAX));
        dp.at(0).at(128) = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j <= 255; ++j) {
                if (dp.at(i).at(j) == LLONG_MAX) continue;
                for (auto &c : C) {
                    int y = j + c;
                    if (y > 255) y = 255;
                    if (y < 0) y = 0;
                    dp.at(i + 1).at(y) = min(dp.at(i + 1).at(y), dp.at(i).at(j) + (ll)pow(y - x.at(i), 2));
                }
            }
        }

        ll ans = LLONG_MAX;
        for (int j = 0; j <= 255; ++j) {
            ans = min(ans, dp.at(N).at(j));
        }
        cout << ans << endl;
    }

    return 0;
}