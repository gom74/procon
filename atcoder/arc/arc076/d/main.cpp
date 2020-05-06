#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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
    return e1.cost < e2.cost;
}

int kruskal(vector<edge> &es, int V) {
    sort(es.begin(), es.end(), comp);
    UnionFind tree(V);
    int ret = 0;
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

    int N;
    cin >> N;
    vector<pair<int, int> > x(N), y(N);
    for (int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        x.at(i) = make_pair(a, i);
        y.at(i) = make_pair(b, i);
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    vector<edge> es;
    for (int i = 1; i < N; ++i) {
        auto p1 = x.at(i - 1);
        auto p2 = x.at(i);
        int x1 = p1.second;
        int x2 = p2.second;
        int dx = abs(p1.first - p2.first);
        es.push_back(edge{x1, x2, dx});
        es.push_back(edge{x2, x1, dx});
        auto q1 = y.at(i - 1);
        auto q2 = y.at(i);
        int y1 = q1.second;
        int y2 = q2.second;
        int dy = abs(q1.first - q2.first);
        es.push_back(edge{y1, y2, dy});
        es.push_back(edge{y2, y1, dy});
    }
    cout << kruskal(es, N) << endl;

    return 0;
}