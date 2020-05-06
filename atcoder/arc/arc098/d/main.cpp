#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A.at(i);
    }

    ll ans = 0;
    ll sum = 0;
    int right = 0;
    for (int left = 0; left < N; ++left) {
        while (right < N && (sum ^ A.at(right)) == (sum + A.at(right))) {
            sum += A.at(right++);
        }
        ans += right - left;
        if (left == right) {
            right++;
        } else {
            sum -= A.at(left);
        }
    }
    cout << ans << endl;

    return 0;
}