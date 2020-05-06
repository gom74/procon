#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int sum = 0;
    int res = 0;
    for (int i = 0; i < 5; ++i) {
        int t;
        cin >> t;
        sum += t + (10 - t % 10) % 10;
        res = max(res, (10 - t % 10) % 10);
    }
    cout << sum - res << endl;

    return 0;
}