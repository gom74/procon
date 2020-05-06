#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    string S;
    cin >> S;
    int x = 0, ans = 0;
    for (int i = 0; i < N; ++i) {
        if (S.at(i) == 'I') {
            x++;
            ans = max(ans, x);
        } else {
            x--;
        }
    }
    cout << ans << endl;

    return 0;
}