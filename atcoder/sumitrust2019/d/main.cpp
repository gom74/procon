#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    string S;
    cin >> N >> S;

    int ans = 0;
    for (int i = 0; i < 1000; ++i) {
        string tmp = to_string(i);
        while (tmp.size() < 3) {
            tmp = '0' + tmp;
        }
        int p1 = -1, p2 = -1, p3 = -1;
        for (int p = 0; p < N; ++p) {
            if (S.at(p) == tmp.at(0)) {
                p1 = p;
                break;
            }
        }
        if (p1 == -1) continue;
        for (int p = p1 + 1; p < N; ++p) {
            if (S.at(p) == tmp.at(1)) {
                p2 = p;
                break;
            }
        }
        if (p2 == -1) continue;
        for (int p = p2 + 1; p < N; ++p) {
            if (S.at(p) == tmp.at(2)) {
                p3 = p;
                break;
            }
        }
        if (p3 != -1) ans++;
    }

    cout << ans << endl;

    return 0;
}