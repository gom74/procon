#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M, C;
    cin >> N >> M >> C;
    vector<int> B(M);
    for (auto &b : B) cin >> b;
    int cnt = 0;
    for (int i = 0; i < N; ++i) {
        int res = C;
        for (int j = 0; j < M; ++j) {
            int A;
            cin >> A;
            res += A * B.at(j);
        }
        if (res > 0) cnt++;
    }
    cout << cnt << endl;

    return 0;
}