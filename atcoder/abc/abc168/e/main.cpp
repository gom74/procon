#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll MOD = 1e9 + 7;

ll modpow(ll x, ll n) {
    if (n == 0) return 1;
    if (n % 2 == 0) {
        return modpow(x * x, n / 2);
    } else {
        return x * modpow(x, n - 1) % MOD;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    map<P, P> mp;
    ll cnt = 0;
    for (int i = 0; i < N; ++i) {
        ll A, B;
        cin >> A >> B;
        if (A == 0 && B == 0) {
            cnt++;
            continue;
        } else if (A == 0) {
            mp[make_pair(1, 0)].second++;
            continue;
        } else if (B == 0) {
            mp[make_pair(1, 0)].first++;
            continue;
        }
        ll g = __gcd(A, B);
        A /= g;
        B /= g;
        if (B < 0) {
            A = -A;
            B = -B;
        }
        if (A < 0) {
            mp[make_pair(B, -A)].second++;
        } else {
            mp[make_pair(A, B)].first++;
        }
    }

    ll ans = 1;
    for (auto &p : mp) {
        auto &u = p.second;
        ans = ans * ((modpow(2, u.first) + modpow(2, u.second) - 1 + MOD) % MOD) % MOD;
    }
    ans = (ans + cnt - 1 + MOD) % MOD;

    cout << ans << endl;

    return 0;
}