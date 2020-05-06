#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int card[10];
    for (int i = 0; i < n; ++i)
    {
        cin >> card[i];
    }
    sort(card, card + n);
    vector<int> seen;
    do
    {
        int num = 0;
        for (int i = 0; i < k; ++i)
        {
            if (card[i] < 10)
            {
                num = num * 10 + card[i];
            }
            else
            {
                num = num * 100 + card[i];
            }
        }
        bool exist = false;
        for (int i = 0; i < seen.size(); ++i)
        {
            if (seen[i] == num)
            {
                exist = true;
            }
        }
        if (!exist)
        {
            seen.push_back(num);
        }
    } while (next_permutation(card, card + n));
    cout << seen.size() << endl;

    return 0;
}