#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N;
    cin >> N;
    vector<ll> cnt(N, 0);
    ll ans = 0;
    for (int i = 0; i < N; ++i) {
        ll A;
        cin >> A;
        if (i >= A) {
            ans += cnt.at(i - A);
        }
        if (i + A < N) {
            cnt.at(i + A)++;
        }
    }
    cout << ans << endl;

    return 0;
}