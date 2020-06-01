#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF = 1e18;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N;
    cin >> N;

    if (N == 1) {
        cout << 0 << endl;
        exit(0);
    }

    map<ll, ll> mp;
    ll res = N;
    for (ll i = 2; i * i <= N; ++i) {
        while (res % i == 0) {
            res /= i;
            mp[i]++;
        }
    }
    if (res != 1) {
        mp[res]++;
    }

    ll ans = 0;
    for (auto &p : mp) {
        ll x = p.second;
        for (ll i = 1; i <= x; ++i) {
            x -= i;
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}