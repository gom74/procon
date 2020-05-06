#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll n, k;
vector<ll> w;

bool check(ll P) {
    ll sum;
    int idx = 0;
    for (int i = 0; i < k; ++i) {
        sum = 0;
        while (w.at(idx) + sum <= P) {
            sum += w.at(idx);
            ++idx;
            if (idx == n) return true;
        }
    }
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> k;
    w.resize(n);
    ll sumw = 0;
    for (int i = 0; i < n; ++i) {
        cin >> w.at(i);
        sumw += w.at(i);
    }
    ll left = -1;
    ll right = sumw + 1;
    while (right - left > 1) {
        ll mid = (left + right) / 2;
        if (check(mid)) {
            right = mid;
        } else {
            left = mid;
        }
    }
    cout << right << endl;

    return 0;
}