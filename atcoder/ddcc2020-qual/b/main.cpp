#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<ll> L(N);
    for (int i = 0; i < N; ++i) {
        ll A;
        cin >> A;
        if (i) {
            L.at(i) = L.at(i - 1) + A;
        } else {
            L.at(i) = A;
        }
    }
    ll ans = LLONG_MAX;
    for (int i = 0; i < N; ++i) {
        ll cost = abs((L.at(N - 1) - L.at(i)) - L.at(i));
        ans = min(ans, cost);
    }

    cout << ans << endl;

    return 0;
}