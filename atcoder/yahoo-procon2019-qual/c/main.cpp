#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll K, A, B;
    cin >> K >> A >> B;

    if (B - A <= 2) {
        cout << K + 1 << endl;
        exit(0);
    }
    ll ans = A;
    K -= A - 1;
    ans += (K / 2) * (B - A);
    K %= 2;
    ans += K;

    cout << ans << endl;

    return 0;
}