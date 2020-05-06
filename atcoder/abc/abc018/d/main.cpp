#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M, P, Q, R;
    cin >> N >> M >> P >> Q >> R;
    vector<int> x(R), y(R), z(R);
    for (int i = 0; i < R; ++i) {
        cin >> x.at(i) >> y.at(i) >> z.at(i);
        x.at(i)--;
        y.at(i)--;
    }

    int ans = 0;
    for (int tmp = 0; tmp < (1 << N); ++tmp) {
        bitset<18> s(tmp);
        if (s.count() != P) continue;
        vector<int> V(M, 0);
        for (int i = 0; i < R; ++i) {
            if (s.test(x.at(i))) {
                V.at(y.at(i)) += z.at(i);
            }
        }
        sort(V.begin(), V.end(), greater<int>());
        int res = 0;
        for (int i = 0; i < Q; ++i) {
            res += V.at(i);
        }
        ans = max(ans, res);
    }

    cout << ans << endl;

    return 0;
}