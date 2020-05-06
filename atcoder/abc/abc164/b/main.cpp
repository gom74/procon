#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int A, B, C, D;
    cin >> A >> B >> C >> D;

    for (int i = 0;; ++i) {
        if (i % 2 == 0) {
            C -= B;
            if (C <= 0) {
                cout << "Yes" << endl;
                break;
            }
        } else {
            A -= D;
            if (A <= 0) {
                cout << "No" << endl;
                break;
            }
        }
    }

    return 0;
}