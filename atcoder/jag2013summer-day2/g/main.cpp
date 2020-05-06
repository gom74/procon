#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

class SegmentTree {
private:
    int n;
    vector<ll> node;

public:
    SegmentTree(vector<ll> V) {
        int sz = V.size();
        n = 1;
        while (n < sz) {
            n *= 2;
        }
        node.resize(2 * n - 1, 0);
        for (int i = 0; i < sz; ++i) {
            node.at(i + n - 1) = V.at(i);
        }
        for (int i = n - 2; i >= 0; --i) {
            node.at(i) = (node.at(2 * i + 1) + node.at(2 * i + 2)) % MOD;
        }
    };
    void update(int x, ll val) {
        x += (n - 1);
        node.at(x) = val;
        while (x > 0) {
            x = (x - 1) / 2;
            node.at(x) = (node.at(2 * x + 1) + node.at(2 * x + 2)) % MOD;
        }
    };
    int find(int a, int b) {
        return find(a, b, 0, 0, n);
    };
    int find(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) return 0;
        if (a <= l && r <= b) return node.at(k);
        int vl = find(a, b, 2 * k + 1, l, (l + r) / 2);
        int vr = find(a, b, 2 * k + 2, (l + r) / 2, r);
        return (vl + vr) % MOD;
    };
    int getat(int x) {
        return node.at(x + n - 1);
    };
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, Q;
    vector<ll> p(N);
    for (int i = 0; i < N; ++i) {
        cin >> p.at(i);
    }
    while (Q--) {
        int l, r;
        cin >> l >> r;
        vector<ll> x(N), y(N);
        for (int i = 0; i < N; ++i) {
            x.at(i) = i + 1;
        }
    }

    return 0;
}