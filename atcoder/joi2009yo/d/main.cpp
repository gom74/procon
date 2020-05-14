#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const vector<int> dy = {1, -1, 0, 0};
const vector<int> dx = {0, 0, 1, -1};

int ans;

void dfs(int y, int x, vector<vector<int> > &A, int depth) {
    A.at(y).at(x) = 0;
    int H = A.size();
    int W = A.at(0).size();
    for (int i = 0; i < 4; ++i) {
        int ny = y + dy.at(i);
        int nx = x + dx.at(i);
        if (ny < 0 || H <= ny) continue;
        if (nx < 0 || W <= nx) continue;
        if (A.at(ny).at(nx) == 0) continue;
        dfs(ny, nx, A, depth + 1);
    }
    A.at(y).at(x) = 1;
    ans = max(ans, depth);

    return;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int H, W;
    cin >> W >> H;
    vector<vector<int> > A(H, vector<int>(W));
    for (auto &V : A) {
        for (auto &x : V) cin >> x;
    }

    ans = 0;
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            if (A.at(y).at(x) == 0) continue;
            dfs(y, x, A, 1);
        }
    }

    cout << ans << endl;

    return 0;
}