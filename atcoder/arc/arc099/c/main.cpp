#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;

    cout << ceil(1.0 * (N - 1) / (K - 1)) << endl;
    exit(0);

    return 0;
}