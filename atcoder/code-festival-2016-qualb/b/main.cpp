#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, A, B;
    cin >> N >> A >> B;
    string S;
    cin >> S;

    int sumAB = 0, sumB = 0;
    for (auto &c : S) {
        if (c == 'a') {
            if (sumAB < A + B) {
                cout << "Yes" << endl;
                sumAB++;
            } else {
                cout << "No" << endl;
            }
        } else if (c == 'b') {
            if (sumAB < A + B && sumB < B) {
                cout << "Yes" << endl;
                sumAB++;
                sumB++;
            } else {
                cout << "No" << endl;
            }
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}