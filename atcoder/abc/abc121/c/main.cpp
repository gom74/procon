#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, M;
    cin >> N >> M;
    vector<P> V(N);
    for (int i = 0; i < N; ++i) {
        ll A, B;
        cin >> A >> B;
        V.at(i) = make_pair(A, B);
    }
    sort(V.begin(), V.end());
    ll cost = 0, cnt = 0;
    for (auto &p : V) {
        if (cnt == M) break;
        cost += p.first * min(M - cnt, p.second);
        cnt = min(M, cnt + p.second);
    }
    cout << cost << endl;

    return 0;
}