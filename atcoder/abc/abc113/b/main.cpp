#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    double T, A;
    cin >> N >> T >> A;
    int ans = 0;
    double mindist = 1e5;
    for (int i = 1; i <= N; ++i) {
        double H;
        cin >> H;
        double _tmp = T - H * 0.006;
        if (abs(A - _tmp) < mindist) {
            ans = i;
            mindist = abs(A - _tmp);
        }
    }
    cout << ans << endl;

    return 0;
}