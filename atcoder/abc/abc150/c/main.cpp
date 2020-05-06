#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

bool check(vector<int> &A, vector<int> &B) {
    int N = A.size();
    for (int i = 0; i < N; ++i) {
        if (A.at(i) != B.at(i)) {
            return false;
        }
    }
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        A.at(i) = i + 1;
    }
    vector<int> P(N), Q(N);
    for (auto &x : P) cin >> x;
    for (auto &x : Q) cin >> x;

    int pnt = 0;
    int a = INT_MAX, b = INT_MAX;
    do {
        if (check(A, P)) a = pnt;
        if (check(A, Q)) b = pnt;
        if (a != INT_MAX && b != INT_MAX) {
            cout << abs(a - b) << endl;
            exit(0);
        }
        pnt++;
    } while (next_permutation(A.begin(), A.end()));

    return 0;
}