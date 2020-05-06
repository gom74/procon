#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N;
    cin >> N;
    vector<ll> C(N);
    ll minodd = 1e9;
    ll minall = 1e9;
    for (int i = 0; i < N; ++i) {
        cin >> C.at(i);
        minall = min(minall, C.at(i));
        if (i % 2 == 0) {
            minodd = min(minodd, C.at(i));
        }
    }

    ll Q;
    cin >> Q;
    ll ans = 0;
    ll n2 = 0;
    ll n3 = 0;
    for (int i = 0; i < Q; ++i) {
        ll opr, x, a;
        cin >> opr;
        if (opr == 1) {
            cin >> x >> a;
            --x;
            ll res = C.at(x);
            res -= n3;
            if (x % 2 == 0) {
                res -= n2;
            }
            if (res >= a) {
                ans += a;
                C.at(x) -= a;
                minall = min(minall, res - a);
                if (x % 2 == 0) {
                    minodd = min(minodd, res - a);
                }
            }
        } else if (opr == 2) {
            cin >> a;
            if (minodd >= a) {
                ans += a * ((N + 1) / 2);
                minodd -= a;
                minall = min(minall, minodd);
                n2 += a;
            }
        } else if (opr == 3) {
            cin >> a;
            if (minall >= a) {
                ans += a * N;
                minodd -= a;
                minall -= a;
                n3 += a;
            }
        }
    }
    cout << ans << endl;

    return 0;
}