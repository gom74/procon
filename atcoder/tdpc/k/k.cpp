#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    pair<int, int> C[N];
    for (int i = 0; i < N; ++i) {
        int x, r;
        cin >> x >> r;
        C[i] = make_pair(x + r, x - r);
    }
    sort(C, C + N);
    int dp[N + 1];
    fill(dp, dp + N, 1 << 30);
    for (int i = 0; i < N; ++i) {
        *lower_bound(dp, dp + N, -C[i].second) = -C[i].second;
    }
    cout << lower_bound(dp, dp + N, 1 << 30) - dp << endl;

    return 0;
}