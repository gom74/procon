#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

ll comb(int n, int r) {
    r = min(r, n - r);
    ll res = 1;
    for (int i = 0; i < r; ++i) {
        res *= (n - i);
    }
    for (int i = 0; i < r; ++i) {
        res /= (r - i);
    }
    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, P;
    cin >> N >> P;
    vector<int> cnt(2, 0);
    for (int i = 0; i < N; ++i) {
        int A;
        cin >> A;
        cnt.at(A % 2)++;
    }

    ll res = pow(2, cnt.at(0));
    ll ans = 0;
    for (int x = P; x <= cnt.at(1); x += 2) {
        ans += res * comb(cnt.at(1), x);
    }

    cout << ans << endl;

    return 0;
}
