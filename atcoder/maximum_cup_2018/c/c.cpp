#include <bits/stdc++.h>
using namespace std;

class UnionFind {
private:
    vector<int> par;
    vector<int> sz;

public:
    UnionFind(int N) {
        par.resize(N, -1);
        sz.resize(N, 1);
    };
    int find(int x) {
        if (par.at(x) == -1) {
            return x;
        } else {
            return par.at(x) = find(par.at(x));
        }
    };
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        par.at(y) = x;
        sz.at(x) += sz.at(y);
    };
    int getSize(int x) {
        return sz.at(find(x));
    };
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    if (N % 2) {
        cout << -1 << endl;
        return 0;
    }
    UnionFind UF(N);
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        UF.unite(i, a - 1);
    }
    for (int i = 0; i < N; ++i) {
        if (UF.find(i) == i) {
            if (UF.getSize(i) % 2) {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    cout << N / 2 << endl;

    return 0;
}