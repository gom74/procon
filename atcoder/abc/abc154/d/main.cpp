#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;
    vector<int> calc(1001, 0);
    for (int i = 1; i <= 1000; ++i) {
        calc.at(i) = calc.at(i - 1) + i;
    }
    vector<double> exv(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        int p;
        cin >> p;
        exv.at(i) = exv.at(i - 1) + 1.0 * calc.at(p) / p;
    }

    double ans = 0;
    for (int i = K; i <= N; ++i) {
        double res = exv.at(i) - exv.at(i - K);
        ans = max(ans, res);
    }

    cout << fixed << setprecision(12) << ans << endl;

    return 0;
}