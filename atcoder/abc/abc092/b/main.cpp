#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, D, X;
    cin >> N >> D >> X;
    for (int i = 0; i < N; ++i) {
        int A;
        cin >> A;
        int day = 1;
        while (day <= D) {
            X++;
            day += A;
        }
    }
    cout << X << endl;

    return 0;
}