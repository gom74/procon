#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    string s, t;
    cin >> N >> s >> t;

    for (int i = N; i > 0; --i) {
        if (s.substr(N - i, i) == t.substr(0, i)) {
            cout << 2 * N - i << endl;
            exit(0);
        }
    }
    cout << 2 * N << endl;

    return 0;
}