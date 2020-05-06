#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    int N;
    cin >> N;
    vector<double> V(N);
    for (auto &x : V) {
        cin >> x;
    }
    sort(V.begin(), V.end());
    double ans = V.at(0);
    for (int i = 1; i < N; ++i) {
        ans = (V.at(i) + ans) / 2;
    }
    cout << ans << endl;

    return 0;
}