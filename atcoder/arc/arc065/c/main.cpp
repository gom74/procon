#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    vector<string> T = {"dream", "dreamer", "erase", "eraser"};
    string S;
    cin >> S;
    reverse(S.begin(), S.end());
    for (auto &t : T) reverse(t.begin(), t.end());

    int idx = 0;
    while (true) {
        for (int i = 0; i < 4; ++i) {
            string &t = T.at(i);
            if (S.substr(idx, 3) == t.substr(0, 3)) {
                idx += t.size();
                break;
            }
            if (i == 3) {
                cout << "NO" << endl;
                exit(0);
            }
        }
        if (idx == S.size()) {
            cout << "YES" << endl;
            exit(0);
        }
    }

    return 0;
}