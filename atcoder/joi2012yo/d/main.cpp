#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const int MOD = 10000;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;
    vector<int> V(N, 0);
    for (int i = 0; i < K; ++i) {
        int A, B;
        cin >> A >> B;
        V.at(A - 1) = B;
    }

    vector<vector<vector<int> > > dp(N, vector<vector<int> >(4, vector<int>(4, 0)));
    if (V.at(0) == 0) {
        for (int k = 1; k <= 3; ++k) {
            dp.at(0).at(0).at(k) = 1;
        }

    } else {
        dp.at(0).at(0).at(V.at(0)) = 1;
    }
    if (V.at(1) == 0) {
        for (int j = 1; j <= 3; ++j) {
            for (int k = 1; k <= 3; ++k) {
                dp.at(1).at(j).at(k) += dp.at(0).at(0).at(j);
            }
        }
    } else {
        for (int j = 1; j <= 3; ++j) {
            dp.at(1).at(j).at(V.at(1)) += dp.at(0).at(0).at(j);
        }
    }
    for (int i = 2; i < N; ++i) {
        if (V.at(i) == 0) {
            for (int j = 1; j <= 3; ++j) {
                for (int k = 1; k <= 3; ++k) {
                    for (int l = 1; l <= 3; ++l) {
                        if (j == k && k == l) continue;
                        (dp.at(i).at(k).at(l) += dp.at(i - 1).at(j).at(k)) %= MOD;
                    }
                }
            }
        } else {
            for (int j = 1; j <= 3; ++j) {
                for (int k = 1; k <= 3; ++k) {
                    if (j == k && k == V.at(i)) continue;
                    (dp.at(i).at(k).at(V.at(i)) += dp.at(i - 1).at(j).at(k)) %= MOD;
                }
            }
        }
    }

    int ans = 0;
    for (auto &V : dp.at(N - 1)) {
        for (auto &x : V) {
            (ans += x) %= MOD;
        }
    }

    cout << ans << endl;

    return 0;
}