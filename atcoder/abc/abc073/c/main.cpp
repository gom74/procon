#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    map<ll, int> mp;
    while (N--) {
        ll A;
        cin >> A;
        mp[A] ^= 1;
    }

    int ans = 0;
    for (auto &p : mp) {
        ans += p.second;
    }
    cout << ans << endl;

    return 0;
}