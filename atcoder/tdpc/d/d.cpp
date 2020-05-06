#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, D;
    cin >> N >> D;
    int a[3] = {}, div[3] = {2, 3, 5};
    for (int i = 0; i < 3; ++i) {
        while (D % div[i] == 0) {
            ++a[i];
            D /= div[i];
        }
    }
    if (D > 1) {
        cout << 0 << endl;
        return 0;
    }
    double dp[N + 1][a[0] + 1][a[1] + 1][a[2] + 1] = {};
    dp[0][0][0][0] = 1.0;
    for (int i = 0; i < N; ++i) {
        for (int x = 0; x <= a[0]; ++x) {
            for (int y = 0; y <= a[1]; ++y) {
                for (int z = 0; z <= a[2]; ++z) {
                    if (dp[i][x][y][z] == 0) break;
                    double p = dp[i][x][y][z] / 6.0;
                    dp[i + 1][x][y][z] += p;
                    dp[i + 1][min(a[0], x + 1)][y][z] += p;
                    dp[i + 1][x][min(a[1], y + 1)][z] += p;
                    dp[i + 1][min(a[0], x + 2)][y][z] += p;
                    dp[i + 1][x][y][min(a[2], z + 1)] += p;
                    dp[i + 1][min(a[0], x + 1)][min(a[1], y + 1)][z] += p;
                }
            }
        }
    }
    cout << fixed << setprecision(10) << dp[N][a[0]][a[1]][a[2]] << endl;

    return 0;
}