#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll A, B, C, K;
    cin >> A >> B >> C >> K;
    cout << ((K % 2) ? B - A : A - B) << endl;

    /*
    A B C A-B
    B+C A+C A+B (B+C)-(A+C) = B-A
    2*A+B+C A+2*B+C A+B+2*C A-B
    */

    return 0;
}