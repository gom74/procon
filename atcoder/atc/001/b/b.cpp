#include <bits/stdc++.h>
using namespace std;

class UnionFind {
private:
    int* par;
    int* rank;

public:
    UnionFind(int N) {
        par = new int[N];
        rank = new int[N];
        for (int i = 0; i < N; ++i) {
            par[i] = i;
            rank[i] = 0;
        }
    };
    ~UnionFind() {
        delete[] par;
        delete[] rank;
    };
    int find(int x) {
        if (par[x] == x) {
            return x;
        } else {
            return par[x] = find(par[x]);
        }
    };
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (rank[x] < rank[y]) {
            par[x] = y;
        } else {
            par[y] = x;
            if (rank[x] == rank[y]) ++rank[x];
        }
    };
    bool same(int x, int y) {
        return find(x) == find(y);
    };
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, Q;
    cin >> N >> Q;
    UnionFind UF(N);
    int P, A, B;
    for (int i = 0; i < Q; ++i) {
        cin >> P >> A >> B;
        if (P == 0) {
            UF.unite(A, B);
        } else if (P == 1) {
            cout << ((UF.same(A, B)) ? "Yes" : "No") << endl;
        }
    }

    return 0;
}