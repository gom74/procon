#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    if (N < 2) {
        cout << 1 << endl;
        exit(0);
    }
    vector<ll> fib(N + 1);
    fib.at(0) = 1;
    fib.at(1) = 1;
    for (int i = 2; i <= N; ++i) {
        fib.at(i) = fib.at(i - 1) + fib.at(i - 2);
    }

    cout << fib.at(N) << endl;

    return 0;
}