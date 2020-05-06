#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int ans = -1e9;
    int minr;
    rep(i, n) {
        int R;
        cin >> R;
        if (!i) {
            minr = R;
            continue;
        }
        ans = max(ans, R - minr);
        minr = min(minr, R);
    }
    cout << ans << endl;

    return 0;
}