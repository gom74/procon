#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string S, T;
    cin >> S >> T;
    if (S == T) {
        cout << "Yes" << endl;
        exit(0);
    }
    for (int i = 0; i < S.size(); ++i) {
        S = S.back() + S.substr(0, S.size() - 1);
        if (S == T) {
            cout << "Yes" << endl;
            exit(0);
        }
    }
    cout << "No" << endl;

    return 0;
}