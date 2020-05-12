#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll A, B, C;
    cin >> A >> B >> C;

    if (A % 2 == 0 || B % 2 == 0 || C % 2 == 0) {
        cout << 0 << endl;
    } else {
        if (A > B) swap(A, B);
        if (B > C) swap(B, C);
        cout << A * B << endl;
    }

    return 0;
}