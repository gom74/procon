#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    int ans = INT_MAX;
    for (int i = 0; i < N; ++i) {
        int A;
        cin >> A;
        int cnt = 0;
        while (A % 2 == 0) {
            A /= 2;
            cnt++;
        }
        ans = min(ans, cnt);
    }

    cout << ans << endl;

    return 0;
}