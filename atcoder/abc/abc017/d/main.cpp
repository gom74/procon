#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
const ll INF = 1e18;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    vector<int> f(N);
    for (int i = 0; i < N; ++i) {
        cin >> f.at(i);
    }

    vector<int> L(N + 1, N + 1);
    map<int, int> mp;
    L.at(0) = 0;
    int right = 0;
    for (int left = 0; left < N; ++left) {
        while (right < N && mp[f.at(right)] == 0) {
            mp[f.at(right)]++;
            right++;
            L.at(right) = min(L.at(right), left);
        }
        if (left == right) {
            right++;
        } else {
            mp[f.at(left)]--;
        }
    }
    vector<ll> dp(N + 1, 0);
    vector<ll> sum(N + 2, 0);
    dp.at(0) = 1;
    sum.at(0) = 0;
    sum.at(1) = 1;
    for (int i = 1; i <= N; ++i) {
        dp.at(i) = (sum.at(i) - sum.at(L.at(i)) + MOD) % MOD;
        sum.at(i + 1) = sum.at(i) + dp.at(i);
    }
    cout << dp.at(N) << endl;

    return 0;
}