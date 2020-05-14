#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    vector<ll> a(N), b(N);
    for (int i = 0; i < N; ++i) {
        cin >> a.at(i) >> b.at(i);
    }
    vector<ll> c(M), d(M);
    for (int i = 0; i < M; ++i) {
        cin >> c.at(i) >> d.at(i);
    }

    for (int i = 0; i < N; ++i) {
        int ans = 0;
        ll mind = LLONG_MAX;
        for (int j = 0; j < M; ++j) {
            ll dist = abs(a.at(i) - c.at(j)) + abs(b.at(i) - d.at(j));
            if (dist < mind) {
                mind = dist;
                ans = j + 1;
            }
        }
        cout << ans << endl;
    }

    return 0;
}