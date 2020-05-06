#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll H, W;
    cin >> H >> W;
    if (H == 1 || W == 1) {
        cout << 1 << endl;
    } else {
        cout << (H * W + 1) / 2 << endl;
    }

    return 0;
}