#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

string add0(int X) {
    string S = to_string(X);
    while (S.size() < 6) {
        S = '0' + S;
    }
    return S;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    vector<int> P(M), Y(M);
    vector<vector<int> > V(N);
    for (int i = 0; i < M; ++i) {
        cin >> P.at(i) >> Y.at(i);
        V.at(P.at(i) - 1).push_back(Y.at(i));
    }
    for (auto &A : V) {
        sort(A.begin(), A.end());
    }
    for (int i = 0; i < M; ++i) {
        auto &A = V.at(P.at(i) - 1);
        int res = lower_bound(A.begin(), A.end(), Y.at(i)) - A.begin() + 1;
        cout << setfill('0') << right << setw(6) << P.at(i);
        cout << setfill('0') << right << setw(6) << res << endl;
    }

    return 0;
}