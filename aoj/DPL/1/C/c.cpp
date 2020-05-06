#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, W;
    cin >> N >> W;
    int v[N + 1], w[N + 1];
    for (int i = 0; i < N; ++i) cin >> v[i] >> w[i];
    int dp[N + 1][W + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= W; ++j) {
            if (j < w[i]) {
                dp[i + 1][j] = dp[i][j];
            } else {
                dp[i + 1][j] = max(dp[i][j], dp[i + 1][j - w[i]] + v[i]);
            }
        }
    }
    cout << dp[N][W] << endl;

    return 0;
}