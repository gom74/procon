#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int D, N;
    cin >> D >> N;
    vector<int> T(D);
    for (auto &x : T) cin >> x;
    vector<int> A(N), B(N), C(N);
    for (int i = 0; i < N; ++i) {
        cin >> A.at(i) >> B.at(i) >> C.at(i);
    }

    vector<vector<int> > dp(D, vector<int>(N, 0));
    for (int i = 1; i < D; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                if (T.at(i - 1) < A.at(j) || B.at(j) < T.at(i - 1)) continue;
                if (T.at(i) < A.at(k) || B.at(k) < T.at(i)) continue;
                dp.at(i).at(k) = max(dp.at(i).at(k), dp.at(i - 1).at(j) + abs(C.at(k) - C.at(j)));
            }
        }
    }

    int ans = 0;
    for (auto &x : dp.at(D - 1)) {
        ans = max(ans, x);
    }

    cout << ans << endl;

    return 0;
}