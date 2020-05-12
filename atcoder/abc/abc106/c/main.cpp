#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string S;
    ll K;
    cin >> S >> K;
    int pnt = 0;
    char res;
    for (int i = 0; i < S.size(); ++i) {
        if (S.at(i) == '1') {
            pnt = i + 1;
        } else {
            res = S.at(i);
            break;
        }
    }

    cout << ((K <= pnt) ? '1' : res) << endl;

    return 0;
}