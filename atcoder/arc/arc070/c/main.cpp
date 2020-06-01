#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int X;
    cin >> X;

    int pnt = 0;
    for (int i = 1;; ++i) {
        pnt += i;
        if (pnt >= X) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}