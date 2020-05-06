#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    set<ll> A;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ll a;
        cin >> a;
        if (!A.empty()) {
            auto itr = A.upper_bound(a);
            ans += distance(itr, A.end());
        }
        A.insert(a);
    }
    cout << ans << endl;

    return 0;
}