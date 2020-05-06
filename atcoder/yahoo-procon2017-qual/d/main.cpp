#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

ll K;

template <class T>
class SegTree {
private:
    int n;
    vector<T> data;
    T def;
    function<T(T, T)> operation;
    function<T(T, T)> update;

    T _query(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) return def;
        if (a <= l && r <= b) {
            return data.at(k);
        } else {
            T c1 = _query(a, b, 2 * k + 1, l, (l + r) / 2);
            T c2 = _query(a, b, 2 * k + 2, (l + r) / 2, r);
            return operation(c1, c2);
        }
    }

public:
    SegTree(size_t _n, T _def, function<T(T, T)> _operation, function<T(T, T)> _update)
        : def(_def), operation(_operation), update(_update) {
        n = 1;
        while (n < _n) {
            n *= 2;
        }
        data = vector<T>(2 * n - 1, def);
    }

    void change(int i, T x) {
        i += n - 1;
        data.at(i) = update(data.at(i), x);
        while (i > 0) {
            i = (i - 1) / 2;
            data.at(i) = operation(data.at(i * 2 + 1), data.at(i * 2 + 2));
        }
    }

    T query(int a, int b) {
        return _query(a, b, 0, 0, n);
    }

    T operator[](int i) {
        return data.at(i + n - 1);
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll Q;
    cin >> Q >> K;
    vector<int> order(Q);
    vector<ll> D(Q), A(Q);
    for (int i = 0; i < Q; ++i) {
        cin >> order.at(i);
        cin >> D.at(i);
        if (order.at(i) == 1) {
            cin >> A.at(i);
        } else {
            A.at(i) = 0;
        }
    }
    vector<ll> DD = D;
    sort(DD.begin(), DD.end());
    DD.erase(unique(DD.begin(), DD.end()), DD.end());
    int N = DD.size();
    SegTree<P> tree(
        N, make_pair(0, 0),
        [](P s, P t) { return make_pair(t.first, s.second + K * (t.first - s.first)); },
        [](P s, P t) { return make_pair(t.first, t.second); });
    for (int i = 0; i < N; ++i) {
        tree.change(i, make_pair(DD.at(i), K * DD.at(i)));
    }
    for (int i = 0; i < Q; ++i) {
        int idx = lower_bound(DD.begin(), DD.end(), D.at(i)) - DD.begin();
        tree.change(idx, make_pair(tree[idx].first, max(0LL, tree[idx].second - A.at(i))));
        if (order.at(i) == 2) {
            cout << K * tree[idx].first - tree[idx].second << endl;
        }
    }

    return 0;
}