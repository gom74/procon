#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    const ll mod = 998244353;

    ll N;
    cin >> N;
    vector<ll> D(N), V(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> D.at(i);
        if ((i == 0 && D.at(i) != 0) || (i != 0 && D.at(i) == 0)) {
            cout << 0 << endl;
            exit(0);
        }
        V.at(D.at(i))++;
    }

    ll ans = 1;
    for (int i = 1; i < N; ++i) {
        ans = ans * V.at(D.at(i) - 1) % mod;
    }
    cout << ans << endl;

    return 0;
}