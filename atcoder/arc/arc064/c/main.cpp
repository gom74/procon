#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, x;
    cin >> N >> x;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a.at(i);
    }

    ll ans = 0;
    for (int i = 1; i < N; ++i) {
        if (a.at(i - 1) + a.at(i) > x) {
            int res = a.at(i - 1) + a.at(i) - x;
            ans += res;
            a.at(i) = max(0, a.at(i) - res);
        }
    }
    cout << ans << endl;

    return 0;
}