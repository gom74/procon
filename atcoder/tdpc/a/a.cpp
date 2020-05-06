#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    int p[N], sump = 0;
    for (int i = 0; i < N; ++i) {
        cin >> p[i];
        sump += p[i];
    }
    int dp[N + 1][sump + 1] = {};
    dp[0][0] = 1;
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= sump; ++j) {
            if (p[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - p[i - 1]];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    int ans = 0;
    for (int j = 0; j <= sump; ++j) {
        ans += dp[N][j];
    }
    cout << ans << endl;

    return 0;
}