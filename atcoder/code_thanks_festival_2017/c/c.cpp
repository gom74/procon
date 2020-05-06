#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;
    ll a, b;
    priority_queue<pll, vector<pll>, greater<pll> > pque;
    for (int i = 0; i < N; ++i) {
        cin >> a >> b;
        pque.push(make_pair(a, b));
    }

    ll ans = 0;
    for (int i = 0; i < K; ++i) {
        pll p = pque.top();
        ans += p.first;
        pque.pop();
        pque.push(make_pair(p.first + p.second, p.second));
    }

    cout << ans << endl;

    return 0;
}