#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll L, R;
    cin >> L >> R;

    ll ans = 2019;
    for (ll i = L; i <= R; ++i) {
        for (ll j = i + 1; j <= R; ++j) {
            if (i * j % 2019 == 0) {
                cout << 0 << endl;
                exit(0);
            }
            ans = min(ans, i * j % 2019);
        }
    }

    cout << ans << endl;

    return 0;
}