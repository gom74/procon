#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

const vector<int> dy = {1, -1, 0, 0};
const vector<int> dx = {0, 0, 1, -1};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int H, W, N;
    cin >> H >> W >> N;
    vector<string> A(H);
    for (auto &s : A) cin >> s;
    vector<P> S(N), G(N);
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            if (A.at(y).at(x) == 'S') {
                S.at(0) = make_pair(y, x);
            } else if ('1' <= A.at(y).at(x) && A.at(y).at(x) <= '9') {
                G.at(A.at(y).at(x) - '1') = make_pair(y, x);
                if (A.at(y).at(x) - '0' == N) continue;
                S.at(A.at(y).at(x) - '0') = make_pair(y, x);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        int sy = S.at(i).first, sx = S.at(i).second;
        int gy = G.at(i).first, gx = G.at(i).second;
        vector<vector<int> > dist(H, vector<int>(W, INT_MAX));
        queue<P> que;
        que.push(make_pair(sy, sx));
        dist.at(sy).at(sx) = 0;
        while (!que.empty()) {
            auto p = que.front();
            que.pop();
            int y = p.first;
            int x = p.second;
            for (int j = 0; j < 4; ++j) {
                int ny = y + dy.at(j);
                int nx = x + dx.at(j);
                if (ny < 0 || H <= ny) continue;
                if (nx < 0 || W <= nx) continue;
                if (A.at(ny).at(nx) == 'X') continue;
                if (dist.at(ny).at(nx) > dist.at(y).at(x) + 1) {
                    dist.at(ny).at(nx) = dist.at(y).at(x) + 1;
                    que.push(make_pair(ny, nx));
                }
            }
        }
        ans += dist.at(gy).at(gx);
    }

    cout << ans << endl;

    return 0;
}