#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int A, B, M;
    cin >> A >> B >> M;
    vector<int> a(A), b(B);
    int mina = INT_MAX, minb = INT_MAX;
    for (auto &p : a) {
        cin >> p;
        mina = min(mina, p);
    }
    for (auto &p : b) {
        cin >> p;
        minb = min(minb, p);
    }
    int ans = mina + minb;
    for (int i = 0; i < M; ++i) {
        int x, y, c;
        cin >> x >> y >> c;
        int res = a.at(x - 1) + b.at(y - 1) - c;
        ans = min(ans, res);
    }
    cout << ans << endl;

    return 0;
}