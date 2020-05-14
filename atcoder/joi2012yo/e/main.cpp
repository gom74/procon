#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

const vector<vector<int> > dy = {{0, -1, -1, 0, 1, 1}, {0, -1, -1, 0, 1, 1}};
const vector<vector<int> > dx = {{1, 0, -1, -1, -1, 0}, {1, 1, 0, -1, 0, 1}};

int Search(int y, int x, vector<vector<int> > &A) {
    int H = A.size() - 2;
    int W = A.at(0).size() - 2;
    vector<vector<int> > used(H + 2, vector<int>(W + 2, 0));
    queue<P> que;
    que.push(make_pair(y, x));
    int res = 0;
    while (!que.empty()) {
        auto p = que.front();
        que.pop();
        int ty = p.first, tx = p.second;
        if (used.at(ty).at(tx)) continue;
        used.at(ty).at(tx) = 1;
        for (int i = 0; i < 6; ++i) {
            int ny = ty + dy.at(ty % 2).at(i);
            int nx = tx + dx.at(ty % 2).at(i);
            if (ny < 0 || H + 1 < ny) continue;
            if (nx < 0 || W + 1 < nx) continue;
            if (used.at(ny).at(nx)) continue;
            if (A.at(ny).at(nx) == 1) {
                res++;
            } else {
                que.push(make_pair(ny, nx));
            }
        }
    }
    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int H, W;
    cin >> W >> H;
    vector<vector<int> > A(H + 2, vector<int>(W + 2, 0));
    for (int y = 1; y <= H; ++y) {
        for (int x = 1; x <= W; ++x) {
            cin >> A.at(y).at(x);
        }
    }

    cout << Search(0, 0, A) << endl;

    return 0;
}