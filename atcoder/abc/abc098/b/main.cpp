#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    string S;
    cin >> N >> S;
    int ans = 0;
    for (int n = 1; n < N; ++n) {
        map<char, int> mp;
        for (int i = 0; i < n; ++i) {
            mp[S.at(i)] = 1;
        }
        int cnt = 0;
        for (int i = n; i < N; ++i) {
            if (mp[S.at(i)]) {
                mp[S.at(i)] = 0;
                cnt++;
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;

    return 0;
}