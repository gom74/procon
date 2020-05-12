#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    vector<int> k(M);
    vector<vector<int> > s(M);
    for (int i = 0; i < M; ++i) {
        cin >> k.at(i);
        s.at(i).resize(k.at(i));
        for (auto &x : s.at(i)) {
            cin >> x;
            x--;
        }
    }
    vector<int> p(M);
    for (auto &x : p) cin >> x;

    int ans = 0;
    for (int tmp = 0; tmp < (1 << N); ++tmp) {
        bitset<12> BIT(tmp);
        bool can = true;
        for (int i = 0; i < M; ++i) {
            int res = 0;
            for (auto &x : s.at(i)) {
                if (BIT.test(x)) res++;
            }
            can *= res % 2 == p.at(i);
        }
        if (can) ans++;
    }

    cout << ans << endl;

    return 0;
}