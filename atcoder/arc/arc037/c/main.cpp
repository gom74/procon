#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool check(ll N, ll K, vector<ll> &a, vector<ll> &b, ll X) {
    ll sum = 0;
    for (int i = 0; i < N; ++i) {
        sum += distance(b.begin(), upper_bound(b.begin(), b.end(), X / a.at(i)));
    }
    return sum >= K;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K;
    cin >> N >> K;
    vector<ll> a(N), b(N);
    for (int i = 0; i < N; ++i) {
        cin >> a.at(i);
    }
    for (int i = 0; i < N; ++i) {
        cin >> b.at(i);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll l = 0;
    ll r = 1e18;
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        if (check(N, K, a, b, mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << r << endl;

    return 0;
}