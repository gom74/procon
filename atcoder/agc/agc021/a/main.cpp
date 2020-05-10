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
    vector<vector<ll> > dp(N + 1, vector<ll>(2, 0));
    dp.at(0).at(0) = S.at(0) - '0';
    dp.at(0).at(1) = S.at(0) - '1';
    for (int i = 1; i < N; ++i) {
        int D = S.at(i) - '0';
        dp.at(i).at(0) = dp.at(i - 1).at(0) + D;
        dp.at(i).at(1) = max(dp.at(i - 1).at(1) + 9, dp.at(i - 1).at(0) + D - 1);
    }
    cout << max(dp.at(N - 1).at(0), dp.at(N - 1).at(1)) << endl;

    return 0;
}