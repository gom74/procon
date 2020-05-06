#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    int minP = INT_MAX;
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        int P;
        cin >> P;
        if (P <= minP) {
            minP = P;
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}