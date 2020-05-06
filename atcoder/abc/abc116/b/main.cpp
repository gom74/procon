#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int f(int n) {
    if (n % 2 == 0) {
        return n / 2;
    } else {
        return 3 * n + 1;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int s;
    cin >> s;

    int ans = 1;
    while (s != 4 && s != 2 && s != 1) {
        s = f(s);
        ans++;
    }
    cout << ans + 3 << endl;

    return 0;
}