#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    int X = N * 100 / 108;
    while (int(X * 1.08) <= N) {
        if (int(X * 1.08) == N) {
            cout << X << endl;
            exit(0);
        } else {
            X++;
        }
    }
    cout << ":(" << endl;

    return 0;
}