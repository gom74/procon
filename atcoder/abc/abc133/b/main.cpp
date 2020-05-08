#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, D;
    cin >> N >> D;
    vector<vector<int> > X(N, vector<int>(D));
    for (auto &V : X) {
        for (auto &x : V) {
            cin >> x;
        }
    }

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            int res = 0;
            for (int k = 0; k < D; ++k) {
                res += pow((X.at(i).at(k) - X.at(j).at(k)), 2);
            }
            int rt = sqrt(res);
            if (rt * rt == res) ans++;
        }
    }

    cout << ans << endl;

    return 0;
}