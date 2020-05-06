#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    int ans = 1;
    while (ans * 2 <= N) {
        ans *= 2;
    }
    cout << ans << endl;

    return 0;
}