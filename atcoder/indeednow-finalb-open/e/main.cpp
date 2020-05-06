#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <class T>
class BinaryIndexedTree {
private:
    vector<T> data;

public:
    BinaryIndexedTree(int sz) {
        data.assign(++sz, 0);
    }

    T sum(int k) {
        T ret = 0;
        for (++k; k > 0; k -= k & -k) ret += data[k];
        return ret;
    }

    void add(int k, T x) {
        for (++k; k < data.size(); k += k & -k) data[k] += x;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H.at(i);
    }
    vector<int> X = H;
    sort(X.begin(), X.end());
    X.erase(unique(X.begin(), X.end()), X.end());
    if (X.size() != N) {
        cout << -1 << endl;
        return 0;
    }

    BinaryIndexedTree<int> BIT(N);
    ll ans = 0;
    for (int i = 0; i < N; ++i) {
        int idx = distance(X.begin(), lower_bound(X.begin(), X.end(), H.at(i)));
        ans += 1LL * H.at(i) * (i - BIT.sum(idx));
        BIT.add(idx, 1);
    }

    cout << ans << endl;

    return 0;
}