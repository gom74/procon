#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = INT_MAX;

class SegmentTree {
private:
    int n;
    vector<int> node;

public:
    SegmentTree(vector<int> V) {
        int sz = V.size();
        n = 1;
        while (n < sz) {
            n *= 2;
        }
        node.resize(2 * n - 1, INF);
        for (int i = 0; i < sz; ++i) {
            node.at(i + n - 1) = V.at(i);
        }
        for (int i = n - 2; i >= 0; --i) {
            node.at(i) = min(node.at(2 * i + 1), node.at(2 * i + 2));
        }
    };
    void update(int x, int val) {
        x += (n - 1);
        node.at(x) = val;
        while (x > 0) {
            x = (x - 1) / 2;
            node.at(x) = min(node.at(2 * x + 1), node.at(2 * x + 2));
        }
    };
    int find(int a, int b, int k = 0, int l = 0, int r = -1) {
        if (r == -1) r = n;
        if (r <= a || b <= l) return INF;
        if (a <= l && r <= b) return node.at(k);
        int vl = find(a, b, 2 * k + 1, l, (l + r) / 2);
        int vr = find(a, b, 2 * k + 2, (l + r) / 2, r);
        return min(vl, vr);
    };
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;
    vector<int> v(n, INF);
    SegmentTree tree(v);
    for (int i = 0; i < q; ++i) {
        int com, x, y;
        cin >> com >> x >> y;
        if (com == 0) {
            tree.update(x, y);
        } else {
            cout << tree.find(x, y + 1) << endl;
        }
    }

    return 0;
}