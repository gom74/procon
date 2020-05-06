#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
    int N, S, K;
    cin >> N >> S >> K;
    long long dp[N + 1][S + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= S; ++j) {
            if (j >= i) {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - i]) % mod;
            } else {
                dp[i][j] = dp[i - 1][j] % mod;
            }
        }
    }
    int res = N * (N - 1) * K / 2;
    int ans = (S < res) ? 0 : dp[N][S - res];
    cout << ans << endl;

    return 0;
}