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
    for (auto &c : S) {
        mp[c] = 1;
    }
    cout << ((mp['N'] == mp['S'] && mp['W'] == mp['E']) ? "Yes" : "No") << endl;

    return 0;
}