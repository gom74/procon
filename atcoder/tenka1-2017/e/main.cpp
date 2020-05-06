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

pair<double, double> solve(double a1, double b1, double c1, double a2, double b2, double c2) {
    /*
    a1*x+b1*y=c1, a2*x+b2*y=c2
    (a1*b2-a2*b1)*x=b2*c1-b1*c2
    (a2*b1-a1*b2)*y=a2*c1-a1*c2
    */
    double x = (b2 * c1 - b1 * c2) / (a1 * b2 - a2 * b1);
    double y = (a2 * c1 - a1 * c2) / (a2 * b1 - a1 * b2);
    return make_pair(x, y);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    int N;
    cin >> N;
    vector<double> A(N), B(N), C(N);
    for (int i = 0; i < N; ++i) {
        cin >> A.at(i) >> B.at(i) >> C.at(i);
    }

    return 0;
}