#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll A, B, C;
    char dot;
    cin >> A >> B >> dot >> C;
    cout << A * (B * 100 + C) / 100 << endl;

    return 0;
}