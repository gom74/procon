#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string S;
    cin >> S;
    int N = S.size();
    vector<int> V(N, 0);
    V.at(0) = (S.at(0) == 'B') ? 1 : 0;
    ll ans = 0;
    for (int i = 1; i < N; ++i) {
        if (S.at(i) == 'B') {
            V.at(i) = V.at(i - 1) + 1;
        } else {
            V.at(i) = V.at(i - 1);
            ans += V.at(i);
        }
    }
    cout << ans << endl;

    return 0;
}