#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll A, B, N;
    cin >> A >> B >> N;
    ll x = min(B - 1, N);
    cout << A * x / B << endl;

    return 0;
}