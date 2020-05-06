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
        return (ret);
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
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A.at(i);
    }
    vector<int> X = A;
    sort(X.begin(), X.end());
    for (int i = 0; i < N; ++i) {
        A.at(i) = distance(X.begin(), lower_bound(X.begin(), X.end(), A.at(i)));
    }
    BinaryIndexedTree<int> BIT(N);
    ll ans = 0;
    for (int i = 0; i < N; ++i) {
        ans += i - BIT.sum(A.at(i));
        BIT.add(A.at(i), 1);
    }
    cout << ans << endl;

    return 0;
}