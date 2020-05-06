#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll X;
    cin >> X;
    ll money = 100;
    ll ans = 0;
    while (money < X) {
        money += money / 100;
        ans++;
    }
    cout << ans << endl;

    return 0;
}