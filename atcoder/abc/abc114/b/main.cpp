#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string S;
    cin >> S;
    int ans = INT_MAX;
    for (int i = 0; i + 2 < S.size(); ++i) {
        ans = min(ans, abs(753 - stoi(S.substr(i, 3))));
    }
    cout << ans << endl;

    return 0;
}