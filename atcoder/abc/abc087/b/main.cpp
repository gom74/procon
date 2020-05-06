#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int A, B, C, X;
    cin >> A >> B >> C >> X;

    int ans = 0;
    for (int i = 0; i <= A; ++i) {
        for (int j = 0; j <= B; ++j) {
            int k = (X - (500 * i + 100 * j)) / 50;
            if (0 <= k && k <= C) {
                ans++;
            }
        }
    }
    cout << ans << endl;

    return 0;
}