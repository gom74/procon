#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int A, B, K;
    cin >> A >> B >> K;
    for (int i = 0; i < K; ++i) {
        if (A + i > B) break;
        cout << A + i << endl;
    }
    for (int i = K - 1; i >= 0; --i) {
        if (B - i <= A + K - 1) continue;
        cout << B - i << endl;
    }

    return 0;
}