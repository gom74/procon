#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll extGCD(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll d = extGCD(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll a, b;
    cin >> a >> b;
    ll x, y;
    extGCD(a, b, x, y);
    cout << x << ' ' << y << endl;

    return 0;
}