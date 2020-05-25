#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, X;
    cin >> N >> X;
    int D;
    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        if (i) {
            D = __gcd(D, abs(X - x));
        } else {
            D = abs(X - x);
        }
    }

    cout << D << endl;

    return 0;
}