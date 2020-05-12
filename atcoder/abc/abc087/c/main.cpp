#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<vector<int> > A(2, vector<int>(N));
    for (auto &V : A) {
        for (auto &x : V) cin >> x;
    }

    vector<vector<int> > dp(2, vector<int>(N, 0));
    dp.at(0).at(0) = A.at(0).at(0);
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i) dp.at(i).at(j) = max(dp.at(i).at(j), dp.at(i - 1).at(j) + A.at(i).at(j));
            if (j) dp.at(i).at(j) = max(dp.at(i).at(j), dp.at(i).at(j - 1) + A.at(i).at(j));
        }
    }

    cout << dp.at(1).at(N - 1) << endl;

    return 0;
}