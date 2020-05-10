#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll A, B, C, K;
    cin >> A >> B >> C >> K;

    ll sum = min(A, K);
    K -= (A + B);
    if (K > 0) {
        sum -= K;
    }
    cout << sum << endl;

    return 0;
}