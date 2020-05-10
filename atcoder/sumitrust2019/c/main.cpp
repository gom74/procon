#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int X;
    cin >> X;
    cout << ((X % 100 <= X / 100 * 5) ? 1 : 0) << endl;

    return 0;
}