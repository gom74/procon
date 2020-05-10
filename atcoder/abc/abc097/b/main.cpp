#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int X;
    cin >> X;
    int ans = 1;
    for (int p = 2; p <= 10; ++p) {
        for (int b = 2; pow(b, p) <= X; ++b) {
            ans = max(ans, (int)pow(b, p));
        }
    }
    cout << ans << endl;

    return 0;
}