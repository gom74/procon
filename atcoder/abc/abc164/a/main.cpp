#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int S, W;
    cin >> S >> W;

    cout << ((S <= W) ? "unsafe" : "safe") << endl;

    return 0;
}