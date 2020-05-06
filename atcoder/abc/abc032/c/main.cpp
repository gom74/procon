#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, K;
    cin >> N >> K;
    vector<ll> s(N);
    for (int i = 0; i < N; ++i) {
        cin >> s.at(i);
        if (s.at(i) == 0) {
            cout << N << endl;
            return 0;
        }
    }

    int ans = 0;
    ll res = 1;
    int right = 0;
    for (int left = 0; left < N; ++left) {
        while (right < N && res * s.at(right) <= K) {
            res *= s.at(right++);
        }
        ans = max(ans, right - left);
        if (left == right) {
            right++;
        } else {
            res /= s.at(left);
        }
    }
    cout << ans << endl;

    return 0;
}