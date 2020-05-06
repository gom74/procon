#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    while (q--) {
        string X, Y;
        cin >> X >> Y;
        int dp[X.size() + 1][Y.size() + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < X.size(); ++i) {
            for (int j = 0; j < Y.size(); ++j) {
                if (X[i] == Y[j]) {
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                } else {
                    dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }
        cout << dp[X.size()][Y.size()] << endl;
    }

    return 0;
}