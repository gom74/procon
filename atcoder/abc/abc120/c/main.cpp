#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string S;
    cin >> S;
    int cnt0 = 0, cnt1 = 0;
    for (auto &c : S) {
        if (c == '0') {
            cnt0++;
        } else {
            cnt1++;
        }
    }
    cout << 2 * min(cnt0, cnt1) << endl;

    return 0;
}