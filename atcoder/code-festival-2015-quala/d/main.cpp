#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool check(vector<ll> &X, ll N, ll T) {
    vector<ll> D(X.size(), 0);
    if (X.at(0) > T) return false;
    D.at(0) = X.at(0) + max((T - X.at(0)) / 2, T - 2 * X.at(0));
    for (int i = 1; i < X.size(); ++i) {
        ll L = max(0LL, X.at(i) - D.at(i - 1) - 1);
        if (L > T) return false;
        ll R = max((T - L) / 2, T - 2 * L);
        D.at(i) = max(D.at(i - 1), X.at(i) + R);
    }
    return D.at(X.size() - 1) >= N - 1;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, M;
    cin >> N >> M;
    vector<ll> X(M);
    for (int i = 0; i < M; ++i) {
        cin >> X.at(i);
        X.at(i)--;
    }

    ll left = -1;
    ll right = 1e10;
    while (right - left > 1) {
        ll mid = (right + left) / 2;
        if (check(X, N, mid)) {
            right = mid;
        } else {
            left = mid;
        }
    }
    cout << right << endl;

    return 0;
}