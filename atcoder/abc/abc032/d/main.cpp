#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e18;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, W;
    cin >> N >> W;
    vector<ll> v(N), w(N);
    ll maxv = 0;
    ll maxw = 0;
    for (int i = 0; i < N; ++i) {
        cin >> v.at(i) >> w.at(i);
        maxv = max(maxv, v.at(i));
        maxw = max(maxw, w.at(i));
    }

    if (N <= 30) {
        ll N2 = N / 2;
        vector<pair<ll, ll> > ps;
        for (int tmp = 0; tmp < (1 << N2); ++tmp) {
            bitset<20> b(tmp);
            ll sv = 0;
            ll sw = 0;
            for (int i = 0; i < N2; ++i) {
                if (b.test(i)) {
                    sv += v.at(i);
                    sw += w.at(i);
                }
            }
            if (sw > W) continue;
            ps.push_back(make_pair(sw, sv));
        }
        sort(ps.begin(), ps.end());
        ll M = 1;
        for (int i = 1; i < ps.size(); ++i) {
            if (ps.at(M - 1).second < ps.at(i).second) {
                ps.at(M++) = ps.at(i);
            }
        }
        ll ans = 0;
        for (int tmp = 0; tmp < (1 << (N - N2)); ++tmp) {
            bitset<20> b(tmp);
            ll sv = 0;
            ll sw = 0;
            for (int i = 0; i < (N - N2); ++i) {
                if (b.test(i)) {
                    sv += v.at(N2 + i);
                    sw += w.at(N2 + i);
                }
            }
            if (sw > W) continue;
            pair<ll, ll> p = make_pair(W - sw, INF);
            ll tv = (lower_bound(ps.begin(), ps.begin() + M, p) - 1)->second;
            ans = max(ans, sv + tv);
        }
        cout << ans << endl;
    } else if (maxw <= 1000) {
        vector<vector<ll> > dp(N + 1, vector<ll>(W + 1, 0));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j <= W; ++j) {
                if (j >= w.at(i)) {
                    dp.at(i + 1).at(j) = max(dp.at(i).at(j), dp.at(i).at(j - w.at(i)) + v.at(i));
                } else {
                    dp.at(i + 1).at(j) = dp.at(i).at(j);
                }
            }
        }
        cout << dp.at(N).at(W) << endl;
    } else if (maxv <= 1000) {
        vector<vector<ll> > dp(N + 1, vector<ll>(N * maxv + 1, INF));
        dp.at(0).at(0) = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j <= N * maxv; ++j) {
                if (j >= v.at(i)) {
                    dp.at(i + 1).at(j) = min(dp.at(i).at(j), dp.at(i).at(j - v.at(i)) + w.at(i));
                } else {
                    dp.at(i + 1).at(j) = dp.at(i).at(j);
                }
            }
        }
        ll ans = 0;
        for (int j = 0; j <= N * maxv; ++j) {
            if (dp.at(N).at(j) <= W) ans = j;
        }
        cout << ans << endl;
    }

    return 0;
}