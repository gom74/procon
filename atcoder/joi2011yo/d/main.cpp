#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> A(N);
    for (auto &x : A) cin >> x;

    vector<vector<ll> > dp(N, vector<ll>(21, 0));
    dp.at(0).at(0) = 1;
    dp.at(1).at(A.at(0)) = 1;
    for (int i = 1; i < N - 1; ++i) {
        for (int j = 0; j <= 20; ++j) {
            if (dp.at(i).at(j) == 0) continue;
            if (j + A.at(i) <= 20) {
                dp.at(i + 1).at(j + A.at(i)) += dp.at(i).at(j);
            }
            if (j - A.at(i) >= 0) {
                dp.at(i + 1).at(j - A.at(i)) += dp.at(i).at(j);
            }
        }
    }

    cout << dp.at(N - 1).at(A.at(N - 1)) << endl;

    return 0;
}