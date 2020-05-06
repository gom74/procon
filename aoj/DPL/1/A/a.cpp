#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int coin[m];
    for (int i = 0; i < m; ++i)
    {
        cin >> coin[i];
    }
    vector<int> dp(n + 1, 1e9);
    dp[0] = 0;
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (coin[j] <= i)
            {
                dp[i] = min(dp[i], dp[i - coin[j]] + 1);
            }
        }
    }
    cout << dp[n] << endl;

    return 0;
}