#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> A(N);
    for (auto &x : A) cin >> x;

    int ans = 1;
    int comp = 0;
    for (int i = 1; i < N; ++i) {
        if (comp == 1) {
            if (A.at(i - 1) > A.at(i)) {
                ans++;
                comp = 0;
            }
        } else if (comp == -1) {
            if (A.at(i - 1) < A.at(i)) {
                ans++;
                comp = 0;
            }
        } else {
            if (A.at(i - 1) < A.at(i)) {
                comp = 1;
            } else if (A.at(i - 1) > A.at(i)) {
                comp = -1;
            }
        }
    }

    cout << ans << endl;

    return 0;
}