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