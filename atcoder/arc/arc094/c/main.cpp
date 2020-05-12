#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int A, B, C;
    cin >> A >> B >> C;

    int M = max(A, max(B, C));
    if (M % 2 != (A + B + C) % 2) M++;

    cout << (3 * M - (A + B + C)) / 2 << endl;

    return 0;
}