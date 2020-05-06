#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    ll x;
    cin >> N >> x;
    vector<ll> a(N);
    for (auto &p : a) {
        cin >> p;
    }
    sort(a.begin(), a.end());
    int pnt = 0;
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        if (x >= a.at(i)) {
            x -= a.at(i);
            ans++;
        } else {
            x = 0;
            break;
        }
    }
    if (x > 0) {
        ans--;
    }
    cout << ans << endl;

    return 0;
}