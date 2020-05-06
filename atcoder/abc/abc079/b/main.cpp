#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<ll> L(100);
    L.at(0) = 2;
    L.at(1) = 1;
    for (int i = 2; i <= N; ++i) {
        L.at(i) = L.at(i - 1) + L.at(i - 2);
    }
    cout << L.at(N) << endl;

    return 0;
}