#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<ll> H(N);
    for (auto &x : H) cin >> x;
    vector<int> V(N, 0);
    for (int i = 1; i < N; ++i) {
        if (H.at(i - 1) >= H.at(i)) {
            V.at(i) = V.at(i - 1) + 1;
        }
    }
    int ans = 0;
    for (auto &x : V) {
        ans = max(ans, x);
    }
    cout << ans << endl;

    return 0;
}