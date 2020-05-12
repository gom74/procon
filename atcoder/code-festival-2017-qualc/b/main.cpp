#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    int res = 1;
    for (int i = 0; i < N; ++i) {
        int A;
        cin >> A;
        res *= (A % 2) ? 1 : 2;
    }
    cout << (int)pow(3, N) - res << endl;

    return 0;
}