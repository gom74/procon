#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int findIdx(vector<int> &A, int x) {
    return lower_bound(A.begin(), A.end(), x) - A.begin();
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;
    vector<int> X1(N), Y1(N), D1(N);
    vector<int> X2(N), Y2(N), D2(N);
    int MAX_X = 0, MAX_Y = 0, MAX_D = 0;
    for (int i = 0; i < N; ++i) {
        cin >> X1.at(i) >> Y1.at(i) >> D1.at(i);
        cin >> X2.at(i) >> Y2.at(i) >> D2.at(i);
        MAX_X = max(MAX_X, X2.at(i));
        MAX_Y = max(MAX_Y, Y2.at(i));
        MAX_D = max(MAX_D, D2.at(i));
    }
    vector<int> X = X1, Y = Y1, D = D1;
    copy(X2.begin(), X2.end(), back_inserter(X));
    copy(Y2.begin(), Y2.end(), back_inserter(Y));
    copy(D2.begin(), D2.end(), back_inserter(D));
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    sort(D.begin(), D.end());
    X.erase(unique(X.begin(), X.end()), X.end());
    Y.erase(unique(Y.begin(), Y.end()), Y.end());
    D.erase(unique(D.begin(), D.end()), D.end());
    int A = X.size();
    int B = Y.size();
    int C = D.size();
    vector<vector<vector<int> > > field;
    field.resize(A, vector<vector<int> >(B, vector<int>(C, 0)));
    for (int i = 0; i < N; ++i) {
        for (int x = findIdx(X, X1.at(i)); x < findIdx(X, X2.at(i)); ++x) {
            for (int y = findIdx(Y, Y1.at(i)); y < findIdx(Y, Y2.at(i)); ++y) {
                for (int d = findIdx(D, D1.at(i)); d < findIdx(D, D2.at(i)); ++d) {
                    field.at(x).at(y).at(d)++;
                }
            }
        }
    }
    ll ans = 0;
    for (int x = 0; x < A - 1; ++x) {
        for (int y = 0; y < B - 1; ++y) {
            for (int d = 0; d < C - 1; ++d) {
                if (field.at(x).at(y).at(d) >= K) {
                    ans += 1LL * (X.at(x + 1) - X.at(x)) * (Y.at(y + 1) - Y.at(y)) * (D.at(d + 1) - D.at(d));
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}