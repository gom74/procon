#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const vector<int> dy = {1, -1, 0, 0};
const vector<int> dx = {0, 0, 1, -1};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int H, W;
    cin >> H >> W;
    vector<string> A(H);
    for (auto &S : A) cin >> S;

    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            if (A.at(y).at(x) == '.') continue;
            bool can = false;
            for (int i = 0; i < 4; ++i) {
                int ny = y + dy.at(i);
                int nx = x + dx.at(i);
                if (ny < 0 || H <= ny) continue;
                if (nx < 0 || W <= nx) continue;
                if (A.at(ny).at(nx) == '#') can = true;
            }
            if (!can) {
                cout << "No" << endl;
                exit(0);
            }
        }
    }
    cout << "Yes" << endl;

    return 0;
}