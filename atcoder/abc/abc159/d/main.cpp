#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> A(N), V(N + 1, 0);
    for (auto &x : A) {
        cin >> x;
        V.at(x)++;
    }
    ll sum = 0;
    for (auto &x : V) {
        sum += 1LL * x * (x - 1) / 2;
    }

    for (auto &x : A) {
        ll n = 1LL * V.at(x);
        cout << sum - n * (n - 1) / 2 + (n - 1) * (n - 2) / 2 << endl;
    }

    return 0;
}