#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M, L, X;
    cin >> N >> M >> L >> X;
    int dp[N + 1][M + 1];
    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j <= M; ++j) dp[i][j] = 1 << 30;
    }
    dp[0][0] = 1;
    int a;
    for (int i = 0; i < N; ++i) {
        cin >> a;
        for (int j = 0; j < M; ++j) {
            if (!j) {
                dp[i + 1][j] = 1;
            }
            if (dp[i][j] < 1 << 30) {
                dp[i + 1][(j + a) % M] = min(dp[i][j] + (j + a) / M, dp[i][(j + a) % M]);
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
            }
        }
    }
    string ans = (dp[N][L] <= X) ? "Yes" : "No";
    cout << ans << endl;

    return 0;
}