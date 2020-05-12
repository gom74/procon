#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll Q, H, S, D, N;
    cin >> Q >> H >> S >> D >> N;

    ll ans = 0;
    if (N >= 2) {
        ll DQ = 8 * Q, DH = 4 * H, DS = 2 * S;
        ll minCost = min(DQ, min(DH, min(DS, D)));
        ans += minCost * (N / 2);
        N %= 2;
    }
    ll SQ = 4 * Q, SH = 2 * H;
    ll minCost = min(SQ, min(SH, S));
    ans += minCost * N;

    cout << ans << endl;

    return 0;
}