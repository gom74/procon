#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int H, W;
    cin >> H >> W;
    vector<vector<char> > A(H + 2, vector<char>(W + 2, '#'));
    for (int y = 1; y <= H; ++y) {
        for (int x = 1; x <= W; ++x) {
            cin >> A.at(y).at(x);
        }
    }
    for (int y = 0; y <= H + 1; ++y) {
        for (int x = 0; x <= W + 1; ++x) {
            cout << A.at(y).at(x);
        }
        cout << endl;
    }

    return 0;
}