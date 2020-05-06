#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    int a, b, c, w;
    int dp[110][110][110];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < N; ++i) {
        cin >> a >> b >> c >> w;
        dp[a][b][c] = max(dp[a][b][c], w);
    }
    for (int i = 0; i <= 100; ++i) {
        for (int j = 0; j <= 100; ++j) {
            for (int k = 0; k <= 100; ++k) {
                if (i) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k]);
                if (j) dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k]);
                if (k) dp[i][j][k] = max(dp[i][j][k], dp[i][j][k - 1]);
            }
        }
    }
    int x, y, z;
    for (int i = 0; i < M; ++i) {
        cin >> x >> y >> z;
        cout << dp[x][y][z] << endl;
    }

    return 0;
}