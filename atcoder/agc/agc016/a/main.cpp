#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string S;
    cin >> S;
    map<char, int> mp;
    for (auto &c : S) mp[c]++;
    if (mp.size() == 1) {
        cout << 0 << endl;
        exit(0);
    }
    int ans = INT_MAX;
    for (char c = 'a'; c <= 'z'; ++c) {
        if (!mp[c]) continue;
        int N = S.size();
        string T = S;
        while (N--) {
            bool allSame = true;
            for (int i = 0; i < N; ++i) {
                if (T.at(i) == c || T.at(i + 1) == c) {
                    T.at(i) = c;
                } else {
                    allSame = false;
                }
            }
            if (allSame) {
                ans = min(ans, (int)S.size() - N);
                break;
            }
        }
    }
    cout << ans << endl;

    return 0;
}