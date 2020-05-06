#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool check(ll R, ll B, ll x, ll y, ll res) {
    R -= res;
    B -= res;
    if (R < 0 || B < 0) return false;
    ll cnt = R / (x - 1) + B / (y - 1);
    return cnt >= res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll R, B;
    cin >> R >> B;
    ll x, y;
    cin >> x >> y;

    ll left = 0;
    ll right = 1e18;
    while (right - left > 1) {
        ll mid = (left + right) / 2;
        check(R, B, x, y, mid) ? left = mid : right = mid;
    }

    cout << left << endl;

    return 0;
}