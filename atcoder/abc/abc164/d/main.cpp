#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    const ll MOD = 2019;

    string S;
    cin >> S;
    ll N = S.size();

    vector<ll> sum(N + 1, 0);
    map<ll, ll> mp;
    mp[0]++;
    ll res = 1;
    for (int i = N - 1; i >= 0; --i) {
        sum.at(i) = (sum.at(i + 1) + res * (S.at(i) - '0')) % MOD;
        mp[sum.at(i)]++;
        res = res * 10 % MOD;
    }
    ll ans = 0;
    for (int i = 0; i < MOD; ++i) {
        ll m = mp[i];
        ans += m * (m - 1) / 2;
    }
    cout << ans << endl;

    return 0;
}