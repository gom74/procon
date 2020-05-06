#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int K, N;
    cin >> K >> N;
    vector<int> A(N + 1);
    for (auto &x : A) {
        cin >> x;
    }
    A.at(N) = A.at(0) + K;
    int res = 0;
    for (int i = 0; i < N; ++i) {
        res = max(res, A.at(i + 1) - A.at(i));
    }
    cout << K - res << endl;

    return 0;
}