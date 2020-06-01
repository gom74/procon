#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string S;
    cin >> S;
    int N = S.size();

    ll ans = 0;
    for (int i = 0; i < N; ++i) {
        if (S.at(i) == 'U') {
            ans += 2 * i + (N - 1 - i);
        } else {
            ans += i + 2 * (N - 1 - i);
        }
    }

    cout << ans << endl;

    return 0;
}