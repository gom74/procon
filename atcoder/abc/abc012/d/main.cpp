#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF = 1e18;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    vector<vector<ll> > d(N, vector<ll>(N, INF));
    for (int i = 0; i < N; ++i) {
        d.at(i).at(i) = 0;
    }
    for (int i = 0; i < M; ++i) {
        int a, b, t;
        cin >> a >> b >> t;
        d.at(a - 1).at(b - 1) = t;
        d.at(b - 1).at(a - 1) = t;
    }

    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                d.at(i).at(j) = min(d.at(i).at(j), d.at(i).at(k) + d.at(k).at(j));
            }
        }
    }
    ll ans = INF;
    for (int i = 0; i < N; ++i) {
        ll maxd = 0;
        for (int j = 0; j < N; ++j) {
            maxd = max(maxd, d.at(i).at(j));
        }
        ans = min(ans, maxd);
    }
    cout << ans << endl;

    return 0;
}