#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll MOD = 1e9 + 7;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N;
    cin >> N;
    ll ans = 1;
    for (ll i = 1; i <= N; ++i) {
        ans = ans * i % MOD;
    }
    cout << ans << endl;

    return 0;
}