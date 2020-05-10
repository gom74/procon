#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    for (auto &x : A) {
        cin >> x;
        x--;
    }

    ll s;
    vector<int> used(N, 0);
    ll pnt = 0;
    while (!used.at(pnt)) {
        used.at(pnt) = 1;
        pnt = A.at(pnt);
    }
    s = pnt;
    pnt = 0;
    ll tos = 0;
    vector<ll> U;
    while (pnt != s) {
        U.push_back(pnt);
        pnt = A.at(pnt);
        tos++;
    }
    vector<ll> V;
    V.push_back(s);
    pnt = s;
    while (A.at(pnt) != s) {
        V.push_back(A.at(pnt));
        pnt = A.at(pnt);
    }
    ll len = V.size();

    if (K < tos) {
        cout << U.at(K) + 1 << endl;
    } else {
        cout << V.at((K - tos) % len) + 1 << endl;
    }

    return 0;
}