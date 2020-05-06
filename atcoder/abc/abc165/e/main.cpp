#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    int a = 1;
    int b = a + M;
    int c = b + 1;
    int d = c + M - 1;
    for (int i = 0; i < M; ++i) {
        if (i % 2 == 0) {
            cout << a << ' ' << b << endl;
            a++;
            b--;
        } else {
            cout << c << ' ' << d << endl;
            c++;
            d--;
        }
    }

    return 0;
}
