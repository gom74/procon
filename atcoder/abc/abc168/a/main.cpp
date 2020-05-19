#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    N %= 10;
    if (N == 3) {
        cout << "bon" << endl;
    } else if (N == 0 || N == 1 || N == 6 || N == 8) {
        cout << "pon" << endl;
    } else {
        cout << "hon" << endl;
    }

    return 0;
}