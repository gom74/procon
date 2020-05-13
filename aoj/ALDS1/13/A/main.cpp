#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

bool exist(vector<int> &y, vector<int> &x, vector<int> &r, vector<int> &c) {
    int k = r.size();
    for (int i = 0; i < k; ++i) {
        bool res = false;
        for (int j = 0; j < 8; ++j) {
            if (r.at(i) == y.at(j) && c.at(i) == x.at(j)) {
                res = true;
            }
        }
        if (!res) return false;
    }
    return true;
}

bool check(vector<vector<char> > &A, int y, int x) {
    for (int i = 1; x + i < 8; ++i) {
        if (A.at(y).at(x + i) == 'Q') return false;
    }
    for (int i = 1; x + i < 8 && y - i >= 0; ++i) {
        if (A.at(y - i).at(x + i) == 'Q') return false;
    }
    for (int i = 1; y - i >= 0; ++i) {
        if (A.at(y - i).at(x) == 'Q') return false;
    }
    for (int i = 1; x - i >= 0 && y - i >= 0; ++i) {
        if (A.at(y - i).at(x - i) == 'Q') return false;
    }
    for (int i = 1; x - i >= 0; ++i) {
        if (A.at(y).at(x - i) == 'Q') return false;
    }
    for (int i = 1; x - i >= 0 && y + i < 8; ++i) {
        if (A.at(y + i).at(x - i) == 'Q') return false;
    }
    for (int i = 1; y + i < 8; ++i) {
        if (A.at(y + i).at(x) == 'Q') return false;
    }
    for (int i = 1; x + i < 8 && y + i < 8; ++i) {
        if (A.at(y + i).at(x + i) == 'Q') return false;
    }
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int k;
    cin >> k;
    vector<int> r(k), c(k);
    for (int i = 0; i < k; ++i) {
        cin >> r.at(i) >> c.at(i);
    }
    vector<int> y(8), x(8);
    for (int i = 0; i < 8; ++i) {
        y.at(i) = i;
        x.at(i) = i;
    }

    do {
        do {
            if (!exist(y, x, r, c)) continue;
            vector<vector<char> > A(8, vector<char>(8, '.'));
            for (int i = 0; i < 8; ++i) {
                A.at(y.at(i)).at(x.at(i)) = 'Q';
            }
            bool can = true;
            for (int i = 0; i < 8; ++i) {
                if (!check(A, y.at(i), x.at(i))) {
                    can = false;
                    break;
                }
            }
            if (can) {
                for (auto &V : A) {
                    for (auto &c : V) {
                        cout << c;
                    }
                    cout << endl;
                }
                exit(0);
            }
        } while (next_permutation(x.begin(), x.end()));
    } while (next_permutation(y.begin(), y.end()));

    return 0;
}