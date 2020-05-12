#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    int ans = 0;
    for (int i = 1; i <= N; i += 2) {
        int cnt = 0;
        for (int x = 1; x * x <= i; ++x) {
            if (i % x == 0) {
                cnt += (x * x == i) ? 1 : 2;
            }
        }
        if (cnt == 8) ans++;
    }
    cout << ans << endl;

    return 0;
}