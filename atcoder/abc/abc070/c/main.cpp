#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    ll ans = 1;
    for (int i = 0; i < N; ++i) {
        ll T;
        cin >> T;
        ans = ans / __gcd(ans, T) * T;
    }
    cout << ans << endl;

    return 0;
}