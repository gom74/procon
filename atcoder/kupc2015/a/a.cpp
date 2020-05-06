#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string S;
        cin >> S;
        int ans = 0;
        for (int i = 0; i < S.size(); ++i)
        {
            if (S.substr(i, 5) == "tokyo" || S.substr(i, 5) == "kyoto")
            {
                ++ans;
                i += 4;
            }
        }
        cout << ans << endl;
    }

    return 0;
}