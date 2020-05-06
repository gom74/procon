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
