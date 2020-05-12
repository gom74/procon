#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    vector<vector<ll> > A(N, vector<ll>(M));
    for (auto &V : A) {
        for (auto &x : V) cin >> x;
    }

    ll ans = 0;
    for (int t1 = 0; t1 < M; ++t1) {
        for (int t2 = 0; t2 < M; ++t2) {
            ll sum = 0;
            for (auto &V : A) {
                sum += max(V.at(t1), V.at(t2));
            }
            ans = max(ans, sum);
        }
    }

    cout << ans << endl;

    return 0;
}