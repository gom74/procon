#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int K, A, B;
    cin >> K >> A >> B;
    int L = K;
    while (L <= B) {
        if (A <= L && L <= B) {
            cout << "OK" << endl;
            return 0;
        }
        L += K;
    }
    cout << "NG" << endl;

    return 0;
}