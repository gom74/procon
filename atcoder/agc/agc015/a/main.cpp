#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, A, B;
    cin >> N >> A >> B;

    if (A > B || (N == 1 && A != B)) {
        cout << 0 << endl;
        exit(0);
    }
    if (N <= 2) {
        cout << 1 << endl;
        exit(0);
    }
    ll maxsum = B * (N - 1) + A;
    ll minsum = A * (N - 1) + B;
    cout << maxsum - minsum + 1 << endl;

    return 0;
}