#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, s, l, p;
    cin >> n;
    int dp[400];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; ++i) {
        cin >> s >> l >> p;
        for (int j = 0; j <= 393; ++j) {
            for (int k = s; j - k >= 0 && k <= l; ++k) {
                dp[j] = max(dp[j], dp[j - k] + p);
            }
        }
    }
    cin >> m;
    int w, ans[m + 1];
    for (int i = 0; i < m; ++i) {
        cin >> w;
        if (dp[w] == 0) {
            cout << -1 << endl;
            return 0;
        }
        ans[i] = dp[w];
    }
    for (int i = 0; i < m; ++i) cout << ans[i] << endl;

    return 0;
}