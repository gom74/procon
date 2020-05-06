#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, K, Q;
    cin >> N >> K >> Q;
    vector<ll> cnt(N, 0);
    for (int i = 0; i < Q; ++i) {
        int A;
        cin >> A;
        cnt.at(A - 1)++;
    }
    for (auto &x : cnt) {
        cout << ((K + x - Q > 0) ? "Yes" : "No") << endl;
    }

    return 0;
}