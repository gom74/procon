#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    map<string, int> mp;
    while (N--) {
        string s;
        cin >> s;
        mp[s]++;
    }
    int M;
    cin >> M;
    while (M--) {
        string t;
        cin >> t;
        mp[t]--;
    }

    int ans = 0;
    for (auto &p : mp) {
        ans = max(ans, p.second);
    }
    cout << ans << endl;

    return 0;
}