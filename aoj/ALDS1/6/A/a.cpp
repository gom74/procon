#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void CountingSort(vector<int> &A, vector<int> &B, vector<int> &C, int k) {
    C.resize(k + 1, 0);
    for (int i = 0; i < A.size(); ++i) {
        ++C.at(A.at(i));
    }
    for (int i = 1; i <= k; ++i) {
        C.at(i) += C.at(i - 1);
    }
    for (int i = 0; i < A.size(); ++i) {
        B.at(C.at(A.at(i)) - 1) = A.at(i);
        --C.at(A.at(i));
    }
    return;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> A(n);
    vector<int> B(n);
    vector<int> C;
    int maxA = 0;
    for (int i = 0; i < n; ++i) {
        cin >> A.at(i);
        maxA = max(maxA, A.at(i));
    }
    CountingSort(A, B, C, maxA);
    for (int i = 0; i < n; ++i) {
        if (i) cout << ' ';
        cout << B.at(i);
    }
    cout << endl;

    return 0;
}