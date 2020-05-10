#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, L;
    cin >> N >> L;
    vector<string> V(N);
    for (auto &x : V) cin >> x;
    sort(V.begin(), V.end());
    for (auto &x : V) cout << x;
    cout << endl;

    return 0;
}