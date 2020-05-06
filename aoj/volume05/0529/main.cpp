#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    while (true) {
        ll N, M;
        cin >> N >> M;
        if (N == 0 && M == 0) break;
        vector<ll> P(N + 1);
        P.at(0) = 0;
        for (int i = 1; i <= N; ++i) {
            cin >> P.at(i);
        }
        vector<ll> V;
        for (int i = 0; i <= N; ++i) {
            for (int j = 0; j <= N; ++j) {
                V.push_back(P.at(i) + P.at(j));
            }
        }
        sort(V.begin(), V.end());

        ll ans = 0;
        for (int i = 0; i < V.size(); ++i) {
            auto itr = upper_bound(V.begin(), V.end(), M - V.at(i));
            if (itr == V.begin()) continue;
            ans = max(ans, V.at(i) + *(itr - 1));
        }
        cout << ans << endl;
    }

    return 0;
}