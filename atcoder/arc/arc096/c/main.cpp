#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    ll ans = 0;
    if (A + B > 2 * C) {
        ll res = min(X, Y);
        ans += 2 * C * res;
        X -= res;
        Y -= res;
    }
    ans += (A > 2 * C) ? 2 * C * X : A * X;
    ans += (B > 2 * C) ? 2 * C * Y : B * Y;

    cout << ans << endl;

    return 0;
}