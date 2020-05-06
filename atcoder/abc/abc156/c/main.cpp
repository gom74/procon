#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> X(N);
    int maxX = 0;
    for (auto &x : X) {
        cin >> x;
        maxX = max(maxX, x);
    }
    int ans = INT_MAX;
    for (int p = 1; p <= maxX; ++p) {
        int res = 0;
        for (auto &x : X) {
            res += (p - x) * (p - x);
        }
        ans = min(ans, res);
    }
    cout << ans << endl;

    return 0;
}