#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<ll> A(3 * N);
    for (auto &x : A) cin >> x;
    sort(A.begin(), A.end());
    ll ans = 0;
    for (int i = 3 * N - 2; i >= N; i -= 2) {
        ans += A.at(i);
    }
    cout << ans << endl;

    return 0;
}