#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    while (true)
    {
        cin >> n >> m;
        if (n == 0 && m == 0)
        {
            break;
        }
        stack<int> S[3];
        for (int i = 0; i < 3; ++i)
        {
            int a, b;
            cin >> a;
            for (int j = 0; j < a; ++j)
            {
                cin >> b;
                S[i].push(b);
            }
        }
    }

    return 0;
}