#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A.at(i);
        if (i == 0) continue;
        if (A.at(i - 1) == A.at(i)) {
            cout << "stay" << endl;
        } else if (A.at(i - 1) < A.at(i)) {
            cout << "up " << A.at(i) - A.at(i - 1) << endl;
        } else {
            cout << "down " << A.at(i - 1) - A.at(i) << endl;
        }
    }

    return 0;
}