#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string S;
    cin >> S;
    int N = S.size();

    int ans = N;
    for (int i = 1; i < N; ++i) {
        if (S.at(i - 1) != S.at(i)) {
            ans = min(ans, max(i, N - i));
        }
    }
    cout << ans << endl;

    return 0;
}