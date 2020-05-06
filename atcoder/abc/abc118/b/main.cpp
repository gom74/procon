#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    vector<int> V(M, 0);
    for (int i = 0; i < N; ++i) {
        int K;
        cin >> K;
        for (int j = 0; j < K; ++j) {
            int A;
            cin >> A;
            V.at(A - 1)++;
        }
    }
    int ans = 0;
    for (auto &x : V) {
        if (x == N) {
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}