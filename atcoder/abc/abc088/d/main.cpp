#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

const vector<int> dy = {1, -1, 0, 0};
const vector<int> dx = {0, 0, 1, -1};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int H, W;
    cin >> H >> W;
    vector<string> A(H);
    for (auto &s : A) cin >> s;

    int cnt = 0;
    for (auto &S : A) {
        for (auto &c : S) {
            if (c == '.') cnt++;
        }
    }

    vector<vector<int> > dist(H, vector<int>(W, INT_MAX));
    queue<P> que;
    que.push(make_pair(0, 0));
    dist.at(0).at(0) = 1;
    while (!que.empty()) {
        auto p = que.front();
        que.pop();
        int y = p.first;
        int x = p.second;
        for (int i = 0; i < 4; ++i) {
            int ny = y + dy.at(i);
            int nx = x + dx.at(i);
            if (ny < 0 || H <= ny) continue;
            if (nx < 0 || W <= nx) continue;
            if (A.at(ny).at(nx) == '#') continue;
            if (dist.at(ny).at(nx) > dist.at(y).at(x) + 1) {
                dist.at(ny).at(nx) = dist.at(y).at(x) + 1;
                que.push(make_pair(ny, nx));
            }
        }
    }

    cout << ((dist.at(H - 1).at(W - 1) == INT_MAX) ? -1 : cnt - dist.at(H - 1).at(W - 1)) << endl;

    return 0;
}