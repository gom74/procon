#include <bits/stdc++.h>
using namespace std;

const int mod = 1e5;

int main() {
    int N, M, S;
    cin >> N >> M >> S;
    long long dp[N * N + 1][S + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 1; i <= N * N; ++i) {
        for (int j = 0; j <= S; ++j) {
            if (j >= i) (dp[i][j] += dp[i][j - i] + dp[i - 1][j - i]) %= mod;
            if (j >= M + 1) (dp[i][j] += mod - dp[i - 1][j - (M + 1)]) %= mod;
        }
    }
    cout << dp[N * N][S] << endl;

    return 0;
}