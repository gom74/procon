#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string S;
    cin >> S;
    vector<int> V(S.size() + 1, 0);
    int ans = 0;
    for (int i = 0; i < S.size(); ++i) {
        if (S.at(i) == 'A' || S.at(i) == 'C' || S.at(i) == 'G' || S.at(i) == 'T') {
            V.at(i + 1) = V.at(i) + 1;
            ans = max(ans, V.at(i + 1));
        }
    }
    cout << ans << endl;

    return 0;
}