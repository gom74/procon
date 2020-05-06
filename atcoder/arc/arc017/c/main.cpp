#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, X;
    cin >> N >> X;
    vector<ll> w(N);
    for (int i = 0; i < N; ++i) {
        cin >> w.at(i);
    }

    ll N2 = N / 2;
    map<ll, ll> mp;
    for (int tmp = 0; tmp < (1 << N2); ++tmp) {
        bitset<20> BIT(tmp);
        ll sw = 0;
        for (int i = 0; i < N2; ++i) {
            if (BIT.test(i)) {
                sw += w.at(i);
            }
        }
        if (sw <= X) {
            mp[sw]++;
        }
    }
    ll ans = 0;
    for (int tmp = 0; tmp < (1 << (N - N2)); ++tmp) {
        bitset<20> BIT(tmp);
        ll sw = 0;
        for (int i = 0; i < N - N2; ++i) {
            if (BIT.test(i)) {
                sw += w.at(N2 + i);
            }
        }
        if (sw <= X) {
            ans += mp[X - sw];
        }
    }

    cout << ans << endl;

    return 0;
}