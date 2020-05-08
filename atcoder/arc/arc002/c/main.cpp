#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    string S;
    cin >> S;

    vector<char> button = {'A', 'B', 'X', 'Y'};
    vector<string> command;
    for (auto &c1 : button) {
        for (auto &c2 : button) {
            string t = {c1, c2};
            command.push_back(t);
        }
    }

    int ans = INT_MAX;
    for (int p = 0; p < command.size(); ++p) {
        for (int q = p + 1; q < command.size(); ++q) {
            string L = command.at(p);
            string R = command.at(q);
            int res = 0;
            for (int i = 0; i < N; ++i) {
                if (i < N - 1 && (S.substr(i, 2) == L || S.substr(i, 2) == R)) {
                    res++;
                    i++;
                } else {
                    res++;
                }
            }
            ans = min(ans, res);
        }
    }
    cout << ans << endl;

    return 0;
}