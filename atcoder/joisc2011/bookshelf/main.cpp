#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = INT_MAX;

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
    int find(int a, int b) {
        return find(a, b, 0, 0, n);
    };
    int find(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) return INF;
        if (a <= l && r <= b) return node.at(k);
        int vl = find(a, b, 2 * k + 1, l, (l + r) / 2);
        int vr = find(a, b, 2 * k + 2, (l + r) / 2, r);
        return min(vl, vr);
    };
};

bool check(vector<int> &A) {
    int N = A.size();
    for (int i = 0; i < N; ++i) {
        if (A.at(i) != i) {
            return false;
        }
    }
    return true;
}

void Move(vector<int> &A, int from, int to) {
    int res = A.at(from);
    if (from < to) {
        for (int i = from; i < to; ++i) {
            A.at(i) = A.at(i + 1);
        }
    } else {
        for (int i = from; i > to; --i) {
            A.at(i) = A.at(i - 1);
        }
    }
    A.at(to) = res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> W(N);
    for (int i = 0; i < N; ++i) {
        cin >> W.at(i);
    }
    SegmentTree tree(W);
    vector<int> X(N);
    for (int i = 0; i < N; ++i) {
        cin >> X.at(i);
        X.at(i)--;
        if (X.at(i) == i) {
            tree.update(i, INF);
        }
    }
    ll ans = 0;
    while (!check(X)) {
        int idx = lower_bound(W.begin(), W.end(), tree.find(0, N)) - W.begin();
        ans += 2 * W.at(idx);
        tree.update(idx, INF);
        Move(X, X.at(idx), idx);
    }
    cout << ans << endl;

    return 0;
}