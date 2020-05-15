#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, M;
    cin >> N >> M;
    if (N > M) swap(N, M);

    if (N == 1 && M == 1) {
        cout << 1 << endl;
    } else if (N == 1) {
        cout << M - 2 << endl;
    } else {
        cout << (N - 2) * (M - 2) << endl;
    }

    return 0;
}