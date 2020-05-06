#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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
    SegTree(size_t _n, T _def, function<T(T, T)> _operation,
            function<T(T, T)> _update)
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

struct box {
    double a;
    double b;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    ll _N, M;
    cin >> _N >> M;
    vector<ll> p(M), np;
    vector<double> a(M), b(M);
    for (int i = 0; i < M; ++i) {
        cin >> p.at(i) >> a.at(i) >> b.at(i);
        np.push_back(--p.at(i));
    }
    sort(np.begin(), np.end());
    np.erase(unique(np.begin(), np.end()), np.end());
    ll N = np.size();

    SegTree<box> st(
        N, box{1, 0},
        [](box s, box t) { return box{s.a * t.a, s.b * t.a + t.b}; },
        [](box s, box t) { return t; });
    double maxans = 1.0;
    double minans = 1.0;
    for (int i = 0; i < M; ++i) {
        ll idx = lower_bound(np.begin(), np.end(), p.at(i)) - np.begin();
        st.change(idx, box{a.at(i), b.at(i)});
        auto res = st.query(0, N);
        maxans = max(maxans, res.a + res.b);
        minans = min(minans, res.a + res.b);
    }

    cout << minans << endl;
    cout << maxans << endl;

    return 0;
}