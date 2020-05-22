#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const int INF = 1e9;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    vector<int> cnt(M, 0);
    vector<vector<int> > sum(M, vector<int>(N + 1, 0));
    for (int i = 1; i <= N; ++i) {
        int A;
        cin >> A;
        cnt.at(A - 1)++;
        sum.at(A - 1).at(i) = 1;
        for (int a = 0; a < M; ++a) {
            sum.at(a).at(i) += sum.at(a).at(i - 1);
        }
    }

    vector<int> dp(1 << M, INF);
    dp.at(0) = 0;
    for (int S = 0; S < 1 << M; ++S) {
        int done = 0;
        for (int i = 0; i < M; ++i) {
            if (S & (1 << i)) done += cnt.at(i);
        }
        for (int nxt = 0; nxt < M; ++nxt) {
            if (S & (1 << nxt)) continue;
            int nS = S ^ (1 << nxt);
            int rest = cnt.at(nxt) - sum.at(nxt).at(done + cnt.at(nxt)) + sum.at(nxt).at(done);
            dp.at(nS) = min(dp.at(nS), dp.at(S) + rest);
        }
    }

    cout << dp.at((1 << M) - 1) << endl;

    return 0;
}