#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    ll T;
    cin >> N >> T;

    ll left = 0, right = T;
    ll sum = 0;
    for (int i = 0; i < N; ++i) {
        ll t;
        cin >> t;
        if (right < t) {
            sum += right - left;
            left = t;
        }
        right = t + T;
    }
    sum += right - left;

    cout << sum << endl;

    return 0;
}