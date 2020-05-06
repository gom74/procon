#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    int Lmax = 0, Rmin = INT_MAX;
    for (int i = 0; i < M; ++i) {
        int L, R;
        cin >> L >> R;
        Lmax = max(Lmax, L);
        Rmin = min(Rmin, R);
    }
    cout << max(0, Rmin - Lmax + 1) << endl;

    return 0;
}