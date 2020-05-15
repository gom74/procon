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

    for (int i = 0; i <= 7; ++i) {
        for (int j = 7 - i; j >= 0; --j) {
            string T = (j == 0) ? S.substr(0, i) : S.substr(0, i) + S.substr(N - j, j);
            if (T == "keyence") {
                cout << "YES" << endl;
                exit(0);
            }
        }
    }
    cout << "NO" << endl;

    return 0;
}