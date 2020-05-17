#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const int INF = 1e8;
const int MAX_N = 1e6;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    vector<int> sum(201, 0);
    for (int i = 1; i <= 200; ++i) {
        sum.at(i) = i * (i + 1) * (i + 2) / 6;
    }

    vector<vector<int> > dp(2, vector<int>(MAX_N, INF));
    dp.at(0).at(0) = 0;
    dp.at(1).at(0) = 0;
    dp.at(0).at(1) = 1;
    dp.at(1).at(1) = 1;
    for (int i = 0; i < MAX_N; ++i) {
        for (auto &x : sum) {
            if (i + x >= MAX_N) break;
            dp.at(0).at(i + x) = min(dp.at(0).at(i + x), dp.at(0).at(i) + 1);
            if (x % 2 == 0) continue;
            dp.at(1).at(i + x) = min(dp.at(1).at(i + x), dp.at(1).at(i) + 1);
        }
    }

    while (true) {
        int N;
        cin >> N;
        if (N == 0) break;
        cout << dp.at(0).at(N) << ' ' << dp.at(1).at(N) << endl;
    }

    return 0;
}