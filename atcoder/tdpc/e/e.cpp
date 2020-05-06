#include <bits/stdc++.h>
using namespace std;

const long long mod = 1000000007;

int main() {
    int D;
    cin >> D;
    string N;
    cin >> N;
    long long dp[N.size() + 1][2][D + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;
    for (int i = 0; i < N.size(); ++i) {
        for (int smaller = 0; smaller <= 1; ++smaller) {
            for (int j = 0; j < D; ++j) {
                for (int num = 0; num <= (smaller ? 9 : N[i] - '0'); ++num) {
                    dp[i + 1][smaller || num < N[i] - '0'][(j + num) % D] = (dp[i + 1][smaller || num < N[i] - '0'][(j + num) % D] + dp[i][smaller][j]) % mod;
                }
            }
        }
    }
    cout << dp[N.size()][0][0] + dp[N.size()][1][0] - 1 << endl;

    return 0;
}