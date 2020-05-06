#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string S;
    cin >> S;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < S.size(); ++i) {
        if (S.at(i) != '0' + i % 2) {
            cnt1++;
        }
        if (S.at(i) != '0' + (i + 1) % 2) {
            cnt2++;
        }
    }
    cout << min(cnt1, cnt2) << endl;

    return 0;
}