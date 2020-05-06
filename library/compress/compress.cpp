#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int compress(vector<int> &x1, vector<int> &x2, int w) {
    int n = x1.size();
    vector<int> X;
    for (int i = 0; i < n; ++i) {
        for (int d = -1; d <= 1; ++d) {
            int tx1 = x1.at(i) + d;
            int tx2 = x2.at(i) + d;
            if (0 <= tx1 && tx1 < w) X.push_back(tx1);
            if (0 <= tx2 && tx2 < w) X.push_back(tx2);
        }
    }
    sort(X.begin(), X.end());
    X.erase(unique(X.begin(), X.end()), X.end());
    for (int i = 0; i < n; ++i) {
        x1.at(i) = lower_bound(X.begin(), X.end(), x1.at(i)) - X.begin();
        x2.at(i) = lower_bound(X.begin(), X.end(), x2.at(i)) - X.begin();
    }
    return X.size();
}