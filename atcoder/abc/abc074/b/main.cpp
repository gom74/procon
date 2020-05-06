#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;
    vector<int> X(N);
    for (auto &x : X) cin >> x;

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        ans += (X.at(i) < K - X.at(i)) ? 2 * X.at(i) : 2 * (K - X.at(i));
    }
    cout << ans << endl;

    return 0;
}