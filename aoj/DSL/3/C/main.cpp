#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, Q;
    cin >> N >> Q;
    vector<ll> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a.at(i);
    }
    for (int cnt = 0; cnt < Q; ++cnt) {
        ll x;
        cin >> x;
        ll ans = 0;
        ll sum = 0;
        int right = 0;
        for (int left = 0; left < N; ++left) {
            while (right < N && sum + a.at(right) <= x) {
                sum += a.at(right++);
            }
            ans += right - left;
            if (right == left) {
                ++right;
            } else {
                sum -= a.at(left);
            }
        }
        cout << ans << endl;
    }

    return 0;
}