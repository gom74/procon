#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<P> A(N);
    vector<ll> V;
    for (int i = 0; i < N; ++i) {
        ll x, y;
        cin >> x >> y;
        A.at(i) = make_pair(x, y);
        V.push_back(x);
        V.push_back(y);
    }
    sort(V.begin(), V.end());
    V.erase(unique(V.begin(), V.end()), V.end());

    ll ans = LLONG_MAX;
    for (auto &s : V) {
        for (auto &g : V) {
            ll sum = 0;
            for (auto &p : A) {
                ll d1 = abs(s - p.first) + abs(p.first - p.second) + abs(p.second - g);
                ll d2 = abs(s - p.second) + abs(p.second - p.first) + abs(p.first - g);
                sum += min(d1, d2);
            }
            ans = min(ans, sum);
        }
    }

    cout << ans << endl;

    return 0;
}