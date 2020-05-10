#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M, X;
    cin >> N >> M >> X;
    vector<int> C(N);
    vector<vector<int> > A(N, vector<int>(M));
    for (int i = 0; i < N; ++i) {
        cin >> C.at(i);
        for (int j = 0; j < M; ++j) {
            cin >> A.at(i).at(j);
        }
    }

    int ans = INT_MAX;
    for (int tmp = 0; tmp < (1 << N); ++tmp) {
        bitset<20> BIT(tmp);
        vector<int> V(M, 0);
        int res = 0;
        for (int i = 0; i < N; ++i) {
            if (BIT.test(i)) {
                res += C.at(i);
                for (int j = 0; j < M; ++j) {
                    V.at(j) += A.at(i).at(j);
                }
            }
        }
        bool can = true;
        for (auto &x : V) {
            if (x < X) {
                can = false;
                break;
            }
        }
        if (can) {
            ans = min(ans, res);
        }
    }

    cout << ((ans == INT_MAX) ? -1 : ans) << endl;

    return 0;
}