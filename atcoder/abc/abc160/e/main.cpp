#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll X, Y, A, B, C;
    cin >> X >> Y >> A >> B >> C;
    vector<ll> p(A), q(B), r(C);
    for (auto &x : p) cin >> x;
    for (auto &x : q) cin >> x;
    for (auto &x : r) cin >> x;
    sort(p.begin(), p.end(), greater<ll>());
    sort(q.begin(), q.end(), greater<ll>());
    sort(r.begin(), r.end(), greater<ll>());

    vector<ll> V;
    for (int i = 0; i < X; ++i) {
        V.push_back(p.at(i));
    }
    for (int i = 0; i < Y; ++i) {
        V.push_back(q.at(i));
    }
    for (auto &x : r) {
        V.push_back(x);
    }
    sort(V.begin(), V.end(), greater<ll>());
    ll sum = 0;
    for (int i = 0; i < X + Y; ++i) {
        sum += V.at(i);
    }

    cout << sum << endl;

    return 0;
}