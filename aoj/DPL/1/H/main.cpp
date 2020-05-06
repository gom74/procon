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
    for (int i = 0; i < N; ++i) {
        cin >> v.at(i) >> w.at(i);
    }

    vector<pair<ll, ll> > P1;
    ll N2 = N / 2;
    for (ll tmp = 0; tmp < (1 << N2); ++tmp) {
        bitset<21> b(tmp);
        ll sv = 0;
        ll sw = 0;
        for (int i = 0; i < N2; ++i) {
            if (b.test(i)) {
                sv += v.at(i);
                sw += w.at(i);
            }
        }
        if (sw > W) continue;
        P1.push_back(make_pair(sw, sv));
    }
    sort(P1.begin(), P1.end());
    ll m = 1;
    for (int i = 1; i < P1.size(); ++i) {
        if (P1.at(m - 1).second < P1.at(i).second) {
            P1.at(m++) = P1.at(i);
        }
    }
    ll ans = 0;
    for (int tmp = 0; tmp < (1 << (N - N2)); ++tmp) {
        bitset<21> b(tmp);
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
        ll tv = (lower_bound(P1.begin(), P1.begin() + m, p) - 1)->second;
        ans = max(ans, sv + tv);
    }
    cout << ans << endl;

    return 0;
}