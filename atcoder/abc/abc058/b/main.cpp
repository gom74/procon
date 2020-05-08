#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string O, E;
    cin >> O >> E;
    int n = O.size();
    int m = E.size();

    for (int i = 0; i < n; ++i) {
        cout << O.at(i);
        if (i < m) cout << E.at(i);
    }
    cout << endl;

    return 0;
}