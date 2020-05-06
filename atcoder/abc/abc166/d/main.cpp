#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll X;
    cin >> X;
    vector<P> V;
    for (int i = 0; 1LL * pow(i, 5) <= LLONG_MAX; ++i) {
        V.push_back(make_pair(i, 1LL * pow(i, 5)));
    }

    for (auto &x : V) {
        for (auto &y : V) {
            if (x.second - y.second == X) {
                cout << x.first << ' ' << y.first << endl;
                return 0;
            } else if (x.second + y.second == X) {
                cout << x.first << ' ' << -1 * y.first << endl;
                return 0;
            }
        }
    }

    return 0;
}