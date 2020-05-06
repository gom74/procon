#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N;
    cin >> N;
    vector<ll> A(N);
    for (auto &x : A) {
        cin >> x;
    }
    sort(A.begin(), A.end());
    ll n1 = A.at(N - 1);
    auto itr = lower_bound(A.begin(), A.end(), n1 / 2);
    if (itr == A.end() - 1) {
        itr--;
    } else if (n1 / 2 - *(itr - 1) < *itr - n1 / 2) {
        itr--;
    }
    cout << n1 << ' ' << *itr << endl;

    return 0;
}