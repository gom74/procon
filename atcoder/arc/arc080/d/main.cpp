#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, H, W;
    cin >> H >> W >> N;
    vector<int> A(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> A.at(i);
    }

    vector<vector<int> > C(H, vector<int>(W));
    int y = 0, x = 0;
    for (int i = 1; i <= N; ++i) {
        int num = A.at(i);
        while (num) {
            C.at(y).at(x) = i;
            num--;
            if (y % 2 == 0) {
                if (x == W - 1) {
                    y++;
                } else {
                    x++;
                }
            } else {
                if (x == 0) {
                    y++;
                } else {
                    x--;
                }
            }
        }
    }
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            if (x) cout << ' ';
            cout << C.at(y).at(x);
        }
        cout << endl;
    }

    return 0;
}