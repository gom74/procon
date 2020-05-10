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
    vector<int> dp(N, 0);
    dp.at(0) = 1;
    if (N > 1) dp.at(1) = (S.at(0) == S.at(1)) ? 1 : 2;
    if (N > 2) dp.at(2) = (S.at(1) == S.at(2)) ? 2 : dp.at(1) + 1;
    for (int i = 3; i < N; ++i) {
        if (S.at(i - 1) != S.at(i)) {
            dp.at(i) = dp.at(i - 1) + 1;
        } else {
            dp.at(i) = dp.at(i - 3) + 2;
        }
    }
    cout << dp.at(N - 1) << endl;

    return 0;
}