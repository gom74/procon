#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, A, B;
    cin >> N >> A >> B;

    if ((B - A) % 2) {
        if (A - 1 < N - B) {
            ll turn = A - 1;
            cout << turn + 1 + ((B - turn - 1) - 1) / 2 << endl;
        } else {
            ll turn = N - B;
            cout << turn + 1 + (N - (A + turn + 1)) / 2 << endl;
        }
    } else {
        cout << (B - A) / 2 << endl;
    }

    return 0;
}