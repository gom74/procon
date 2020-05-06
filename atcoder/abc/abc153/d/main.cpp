#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll H;
    cin >> H;
    ll ans = 0;
    ll res = 1;
    while (H) {
        H /= 2;
        ans += res;
        res *= 2;
    }
    cout << ans << endl;

    return 0;
}