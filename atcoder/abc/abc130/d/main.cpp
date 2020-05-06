#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    for (auto &x : A) cin >> x;

    ll sum = 0;
    ll ans = 0;
    int right = 0;
    for (int left = 0; left < N; ++left) {
        while (right < N && sum + A.at(right) < K) {
            sum += A.at(right);
            right++;
        }
        ans += N - right;
        if (left == right) {
            right++;
        } else {
            sum -= A.at(left);
        }
    }

    cout << ans << endl;

    return 0;
}