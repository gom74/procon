#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll A, B, C;
    cin >> A >> B >> C;
    ll X = A, Y = B, Z = C;
    ll cnt = 0;
    while (A % 2 == 0 && B % 2 == 0 && C % 2 == 0) {
        ll a = (B + C) / 2;
        ll b = (A + C) / 2;
        ll c = (A + B) / 2;
        if (a == X && b == Y && c == Z) {
            cout << -1 << endl;
            exit(0);
        }
        A = a;
        B = b;
        C = c;
        cnt++;
    }
    cout << cnt << endl;

    return 0;
}