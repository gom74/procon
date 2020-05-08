#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string S;
    cin >> S;
    if (S.at(0) != 'A') {
        cout << "WA" << endl;
        exit(0);
    }
    int cnt = 0;
    for (int i = 1; i < S.size(); ++i) {
        if (2 <= i && i <= S.size() - 2 && S.at(i) == 'C') {
            cnt++;
        } else {
            if (S.at(i) < 'a' || 'z' < S.at(i)) {
                cout << "WA" << endl;
                exit(0);
            }
        }
    }
    cout << ((cnt == 1) ? "AC" : "WA") << endl;

    return 0;
}