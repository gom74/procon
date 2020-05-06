#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int A, B;
    string S;
    cin >> A >> B >> S;

    bool yes = true;
    for (int i = 0; i < S.size(); ++i) {
        if (i < A || A < i) {
            if (S.at(i) < '0' || '9' < S.at(i)) {
                yes = false;
                break;
            }
        } else if (i == A) {
            if (S.at(i) != '-') {
                yes = false;
                break;
            }
        }
    }
    cout << ((yes) ? "Yes" : "No") << endl;

    return 0;
}