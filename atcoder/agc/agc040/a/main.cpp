#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string S;
    cin >> S;
    int N = S.size();
    vector<int> A(N + 1, 0);

    for (int i = 0; i < N; ++i) {
        if (S.at(i) == '<') {
            A.at(i + 1) = A.at(i) + 1;
        }
    }
    for (int i = N - 1; i >= 0; --i) {
        if (S.at(i) == '>') {
            A.at(i) = max(A.at(i), A.at(i + 1) + 1);
        }
    }

    ll ans = 0;
    for (auto &x : A) {
        ans += x;
    }
    cout << ans << endl;

    return 0;
}