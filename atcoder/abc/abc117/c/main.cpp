#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    if (N >= M) {
        cout << 0 << endl;
        exit(0);
    }
    vector<int> X(M);
    for (auto &x : X) cin >> x;
    sort(X.begin(), X.end());

    vector<int> DX(M - 1);
    for (int i = 0; i < M - 1; ++i) {
        DX.at(i) = X.at(i + 1) - X.at(i);
    }
    sort(DX.begin(), DX.end(), greater<int>());

    int ans = X.back() - X.front();
    for (int i = 0; i < N - 1; ++i) {
        ans -= DX.at(i);
    }

    cout << ans << endl;

    return 0;
}