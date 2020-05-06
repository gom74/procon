#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

bool check(vector<vector<int> > &seen) {
    for (int i = 0; i < 3; ++i) {
        bool ok = true;
        for (int j = 0; j < 3; ++j) {
            ok *= seen.at(i).at(j);
        }
        if (ok) return true;
    }
    for (int j = 0; j < 3; ++j) {
        bool ok = true;
        for (int i = 0; i < 3; ++i) {
            ok *= seen.at(i).at(j);
        }
        if (ok) return true;
    }
    if (seen.at(0).at(0) * seen.at(1).at(1) * seen.at(2).at(2)) return true;
    if (seen.at(2).at(0) * seen.at(1).at(1) * seen.at(0).at(2)) return true;
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    vector<vector<int> > A(3, vector<int>(3));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> A.at(i).at(j);
        }
    }
    int N;
    cin >> N;
    vector<vector<int> > seen(3, vector<int>(3, 0));
    for (int cnt = 0; cnt < N; ++cnt) {
        int b;
        cin >> b;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (A.at(i).at(j) == b) {
                    seen.at(i).at(j) = 1;
                }
            }
        }
    }
    cout << ((check(seen)) ? "Yes" : "No") << endl;

    return 0;
}