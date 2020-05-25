#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    vector<char> ans(s.size());
    int pnt = 0;
    for (auto &c : s) {
        switch (c) {
            case '0':
                ans.at(pnt) = '0';
                pnt++;
                break;
            case '1':
                ans.at(pnt) = '1';
                pnt++;
                break;
            case 'B':
                pnt = max(0, pnt - 1);
                break;
            default:
                break;
        }
    }

    for (int i = 0; i < pnt; ++i) {
        cout << ans.at(i);
    }
    cout << endl;

    return 0;
}