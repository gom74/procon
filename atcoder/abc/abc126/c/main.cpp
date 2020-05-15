#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;

    double ans = 0.0;
    for (int i = 1; i <= N; ++i) {
        int score = i;
        double res = 1.0 / N;
        while (score < K) {
            score *= 2;
            res /= 2.0;
        }
        ans += res;
    }

    cout << fixed << setprecision(12) << ans << endl;

    return 0;
}