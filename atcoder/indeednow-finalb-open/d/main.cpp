#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

const vector<int> dx = {1, -1, 0, 0};
const vector<int> dy = {0, 0, 1, -1};

#pragma region union_find
class UnionFind {
private:
    vector<int> par;
    vector<int> rank;

public:
    UnionFind(int N) {
        par.resize(N);
        rank.resize(N, 0);
        for (int i = 0; i < N; ++i) {
            par.at(i) = i;
        }
    };
    int find(int x) {
        if (par.at(x) == x) {
            return x;
        } else {
            return par.at(x) = find(par.at(x));
        }
    };
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (rank.at(x) < rank.at(y)) {
            par.at(x) = y;
        } else {
            par.at(y) = x;
            if (rank.at(x) == rank.at(y)) ++rank.at(x);
        }
    };
    bool same(int x, int y) {
        return find(x) == find(y);
    };
};
#pragma endregion

#pragma region kruskal
struct edge {
    int from;
    int to;
    int cost;
};

bool comp(const edge &e1, const edge &e2) {
    return e1.cost > e2.cost;
}

ll kruskal(vector<edge> &es, int V) {
    sort(es.begin(), es.end(), comp);
    UnionFind tree(V);
    ll ret = 0;
    for (auto &e : es) {
        if (!tree.same(e.from, e.to)) {
            tree.unite(e.from, e.to);
            ret += e.cost;
        }
    }
    return ret;
}
#pragma endregion

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int H, W;
    cin >> H >> W;
    int sx, sy, gx, gy;
    cin >> sx >> sy >> gx >> gy;
    sx--;
    sy--;
    gx--;
    gy--;
    vector<vector<int> > P(W, vector<int>(H));
    ll ans = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> P.at(j).at(i);
            ans += P.at(j).at(i);
        }
    }
    vector<edge> es;
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx.at(i);
                int ny = y + dy.at(i);
                if (nx < 0 || nx >= W) continue;
                if (ny < 0 || ny >= H) continue;
                es.push_back(edge{y * W + x, ny * W + nx, P.at(x).at(y) * P.at(nx).at(ny)});
                es.push_back(edge{ny * W + nx, y * W + x, P.at(x).at(y) * P.at(nx).at(ny)});
            }
        }
    }
    ans += kruskal(es, H * W);
    cout << ans << endl;

    return 0;
}