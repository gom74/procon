#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int N, M, Q;
vector<int> a, b, c, d;
vector<int> A;
int ans;

void dfs(int idx, int pre) {
    if (idx == N) {
        int res = 0;
        for (int i = 0; i < Q; ++i) {
            if (A.at(b.at(i)) - A.at(a.at(i)) == c.at(i)) {
                res += d.at(i);
            }
        }
        ans = max(ans, res);
    } else {
        for (int i = pre; i <= M; ++i) {
            A.at(idx) = i;
            dfs(idx + 1, i);
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> M >> Q;
    a.resize(Q);
    b.resize(Q);
    c.resize(Q);
    d.resize(Q);
    A.resize(N);
    for (int i = 0; i < Q; ++i) {
        cin >> a.at(i) >> b.at(i) >> c.at(i) >> d.at(i);
        a.at(i)--;
        b.at(i)--;
    }
    ans = 0;
    dfs(0, 1);
    cout << ans << endl;

    return 0;
}