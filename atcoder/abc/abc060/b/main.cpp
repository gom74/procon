#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int A, B, C;
    cin >> A >> B >> C;
    int sum = A % B;
    while (true) {
        if (sum == C) {
            cout << "YES" << endl;
            exit(0);
        }
        sum = (sum + A) % B;
        if (sum == A % B) {
            cout << "NO" << endl;
            exit(0);
        }
    }

    return 0;
}