#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> cnt(100000, 0);
    int maxa = 0;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        cnt.at(a)++;
        maxa = max(maxa, a);
    }
    int ans = 0;
    for (int X = 1; X < 99999; ++X) {
        int res = cnt.at(X - 1) + cnt.at(X) + cnt.at(X + 1);
        ans = max(ans, res);
    }
    cout << ans << endl;

    return 0;
}