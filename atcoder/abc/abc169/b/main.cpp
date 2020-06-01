#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF = 1e18;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<ll> A(N);
    for (auto &x : A) {
        cin >> x;
        if (x == 0) {
            cout << 0 << endl;
            exit(0);
        }
    }

    ll ans = 1;
    for (auto &x : A) {
        if (x > INF / ans) {
            ans = -1;
            break;
        }
        ans *= x;
    }

    cout << ans << endl;

    return 0;
}