#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string S;
    cin >> S;
    int N = S.size();
    for (int L = N - 1; L > 1; --L) {
        if (L % 2 == 1) continue;
        string _S = S.substr(0, L);
        string s1 = _S.substr(0, L / 2);
        string s2 = _S.substr(L / 2, L / 2);
        if (s1 == s2) {
            cout << L << endl;
            exit(0);
        }
    }

    return 0;
}