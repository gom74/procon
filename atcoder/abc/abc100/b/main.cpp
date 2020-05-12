#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int D, N;
    cin >> D >> N;
    if (N == 100) N = 101;
    ll ans = N * pow(100, D);
    cout << ans << endl;

    return 0;
}