#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string S, T;
    cin >> S >> T;
    int N = S.size();
    cout << ((S == T.substr(0, N)) ? "Yes" : "No") << endl;

    return 0;
}