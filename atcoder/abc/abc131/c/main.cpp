#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

ll A, B, C, D;

ll calc(ll N) {
    return N / C + N / D - N / (C / __gcd(C, D) * D);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> A >> B >> C >> D;
    cout << B - A + 1 - (calc(B) - calc(A - 1)) << endl;

    return 0;
}