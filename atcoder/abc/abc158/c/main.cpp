#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    double A, B;
    cin >> A >> B;
    for (int i = 1; i <= 2000; ++i) {
        double tax8 = i * 0.08;
        double tax10 = i * 0.1;
        if (A <= tax8 && tax8 < A + 1 && B <= tax10 && tax10 < B + 1) {
            cout << i << endl;
            exit(0);
        }
    }
    cout << -1 << endl;

    return 0;
}