#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;
    vector<ll> h(N);
    for (auto &x : h) cin >> x;
    sort(h.begin(), h.end());
    ll ans = LLONG_MAX;
    for (int i = 0; i + K - 1 < N; ++i) {
        ans = min(ans, h.at(i + K - 1) - h.at(i));
    }
    cout << ans << endl;

    return 0;
}