#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

void insertionSort(vector<int> &A) {
    for (int i = 1; i < A.size(); ++i) {
        int v = A.at(i);
        int j = i - 1;
        while (j >= 0 && A.at(j) > v) {
            A.at(j + 1) = A.at(j);
            --j;
        }
        A.at(j + 1) = v;
        rep(i, A.size()) {
            if (i) cout << ' ';
            cout << A.at(i);
        }
        cout << endl;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A.at(i);
    rep(i, A.size()) {
        if (i) cout << ' ';
        cout << A.at(i);
    }
    cout << endl;
    insertionSort(A);

    return 0;
}