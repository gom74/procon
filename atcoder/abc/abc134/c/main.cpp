#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> A(N);
    int maxi = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A.at(i);
        if (A.at(i) > A.at(maxi)) {
            maxi = i;
        }
    }
    sort(A.begin(), A.end(), greater<int>());
    for (int i = 0; i < N; ++i) {
        if (i == maxi) {
            cout << A.at(1) << endl;
        } else {
            cout << A.at(0) << endl;
        }
    }

    return 0;
}