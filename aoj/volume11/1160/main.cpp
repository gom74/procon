#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

void dfs(int y, int x, vector<vector<int> > &C, vector<vector<int> > &used) {
    used.at(y).at(x) = 1;
    int H = C.size();
    int W = C.at(0).size();
    for (int dy = -1; dy <= 1; ++dy) {
        for (int dx = -1; dx <= 1; ++dx) {
            int ny = y + dy;
            int nx = x + dx;
            if (ny < 0 || H <= ny) continue;
            if (nx < 0 || W <= nx) continue;
            if (used.at(ny).at(nx)) continue;
            if (C.at(ny).at(nx) == 0) continue;
            dfs(ny, nx, C, used);
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    while (true) {
        int W, H;
        cin >> W >> H;
        if (W == 0 && H == 0) break;
        vector<vector<int> > C(H, vector<int>(W));
        vector<vector<int> > used(H, vector<int>(W, 0));
        for (int y = 0; y < H; ++y) {
            for (int x = 0; x < W; ++x) {
                cin >> C.at(y).at(x);
            }
        }

        int ans = 0;
        for (int y = 0; y < H; ++y) {
            for (int x = 0; x < W; ++x) {
                if (C.at(y).at(x) == 1 && used.at(y).at(x) == 0) {
                    ans++;
                    dfs(y, x, C, used);
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}