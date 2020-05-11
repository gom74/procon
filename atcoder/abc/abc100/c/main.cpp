#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    int ans = 0;
    while (N--) {
        ll a;
        cin >> a;
        int res = 0;
        while (a % 2 == 0) {
            a /= 2;
            res++;
        }
        ans += res;
    }
    cout << ans << endl;

    return 0;
}