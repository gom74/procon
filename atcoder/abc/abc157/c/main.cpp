#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    vector<int> s(M);
    vector<char> c(M);
    for (int i = 0; i < M; ++i) {
        cin >> s.at(i) >> c.at(i);
        s.at(i)--;
    }

    for (int n = 0; n < pow(10, N); ++n) {
        string t = to_string(n);
        if (t.size() != N) continue;
        bool can = true;
        for (int i = 0; i < M; ++i) {
            if (t.at(s.at(i)) != c.at(i)) {
                can = false;
                break;
            }
        }
        if (can) {
            cout << t << endl;
            exit(0);
        }
    }
    cout << -1 << endl;

    return 0;
}