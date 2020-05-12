#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;
    vector<ll> a(N);
    for (auto &x : a) cin >> x;

    ll ans = LLONG_MAX;
    for (int tmp = 0; tmp < (1 << N); ++tmp) {
        bitset<20> BIT(tmp);
        if (!BIT.test(0)) continue;
        if (BIT.count() < K) continue;
        ll cost = 0;
        ll h = a.at(0);
        for (int i = 1; i < N; ++i) {
            h = max(h, a.at(i - 1));
            if (!BIT.test(i)) continue;
            if (a.at(i) <= h) {
                cost += h + 1 - a.at(i);
                h++;
            }
        }
        ans = min(ans, cost);
    }

    cout << ans << endl;

    return 0;
}