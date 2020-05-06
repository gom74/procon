#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll a, b;
    cin >> a >> b;
    if (a > 0 && b > 0) {
        cout << "Positive" << endl;
    } else if (a * b <= 0) {
        cout << "Zero" << endl;
    } else {
        if ((b - a + 1) % 2) {
            cout << "Negative" << endl;
        } else {
            cout << "Positive" << endl;
        }
    }

    return 0;
}