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

    int V, E;
    cin >> V >> E;
    vector<edge> es;
    for (int i = 0; i < E; ++i) {
        int s, t, w;
        cin >> s >> t >> w;
        es.push_back(edge{s, t, w});
        es.push_back(edge{t, s, w});
    }

    cout << kruskal(es, V) << endl;

    return 0;
}