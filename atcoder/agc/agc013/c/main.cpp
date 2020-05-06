#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, L, T;
    cin >> N >> L >> T;
    vector<ll> X(N), W(N), A(N);
    for (int i = 0; i < N; ++i) {
        cin >> X.at(i) >> W.at(i);
        if (W.at(i) == 1) {
            A.at(i) = (X.at(i) + T) % L;
        } else {
            A.at(i) = ((X.at(i) - T) % L + L) % L;
        }
    }
    ll A0 = A.at(0);
    sort(A.begin(), A.end());
    ll pnt = 0;
    for (int i = 0; i < N; ++i) {
        if (W.at(0) == W.at(i)) continue;
        ll d = (W.at(0) == 1) ? X.at(i) - X.at(0) : L - (X.at(i) - X.at(0));
        if (2 * T < d) continue;
        if (W.at(0) == 1) {
            pnt += (2 * T - d) / L + 1;
            pnt %= N;
        } else {
            pnt -= (2 * T - d) / L + 1;
            pnt = (pnt % N + N) % N;
        }
    }
    ll X0;
    for (int i = 0; i < N; ++i) {
        if (A.at(i) == A0) {
            X0 = i;
            if (W.at(0) != 1) break;
        }
    }
    ll ofs = (X0 - pnt + N) % N;
    for (int i = 0; i < N; ++i) {
        cout << A.at((ofs + i) % N) << endl;
    }

    return 0;
}