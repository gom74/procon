#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    while (true) {
        ll d;
        cin >> d;
        if (d == 0) break;
        ll n, m;
        cin >> n >> m;
        vector<ll> S(n);
        S.at(0) = 0;
        for (int i = 1; i < n; ++i) {
            cin >> S.at(i);
        }
        sort(S.begin(), S.end());
        ll sum = 0;
        for (int i = 0; i < m; ++i) {
            ll c;
            cin >> c;
            auto itr = upper_bound(S.begin(), S.end(), c);
            if (itr != S.end()) {
                sum += min(*itr - c, c - *(itr - 1));
            } else {
                sum += min(d - c, c - *(itr - 1));
            }
        }
        cout << sum << endl;
    }

    return 0;
}