#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<ll> A(N + 1);
    for (auto &x : A) cin >> x;

    ll ans = 0;
    for (int i = 0; i < N; ++i) {
        ll B;
        cin >> B;
        ans += min(A.at(i), B);
        B = max(0LL, B - A.at(i));
        ans += min(A.at(i + 1), B);
        A.at(i + 1) = max(0LL, A.at(i + 1) - B);
    }

    cout << ans << endl;

    return 0;
}