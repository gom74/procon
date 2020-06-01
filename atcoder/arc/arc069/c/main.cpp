#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, M;
    cin >> N >> M;

    ll ans = 0;
    ans += min(N, M / 2);
    M = max(0LL, M - 2 * N);
    ans += M / 4;

    cout << ans << endl;

    return 0;
}