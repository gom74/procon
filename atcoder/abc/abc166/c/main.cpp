#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, M;
    cin >> N >> M;
    vector<ll> H(N);
    for (auto &h : H) {
        cin >> h;
    }
    vector<vector<ll> > G(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        G.at(a - 1).push_back(b - 1);
        G.at(b - 1).push_back(a - 1);
    }

    ll ans = 0;
    for (int i = 0; i < N; ++i) {
        bool yes = true;
        for (auto &x : G.at(i)) {
            if (H.at(i) <= H.at(x)) {
                yes = false;
                break;
            }
        }
        if (yes) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}