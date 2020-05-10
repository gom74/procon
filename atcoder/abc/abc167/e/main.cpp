#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll MOD = 998244353;

const int MAX = 510000;

long long fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

long long COM(int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

ll modpow(ll x, ll n) {
    if (x == 1) {
        return 1;
    } else if (n == 0) {
        return 1;
    } else {
        if (n % 2 == 0) {
            return modpow(x * x % MOD, n / 2);
        } else {
            return x * modpow(x, n - 1) % MOD;
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, M, K;
    cin >> N >> M >> K;
    COMinit();

    ll ans = 0;
    for (int i = 0; i <= K; ++i) {
        (ans += (M * modpow(M - 1, N - i - 1) % MOD) * (COM(N - 1, i) % MOD)) %= MOD;
    }

    cout << ans << endl;

    return 0;
}