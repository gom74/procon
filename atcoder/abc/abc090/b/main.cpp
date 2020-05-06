#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int A, B;
    cin >> A >> B;
    int ans = 0;
    for (int N = A; N <= B; ++N) {
        string s = to_string(N);
        string t = s;
        reverse(t.begin(), t.end());
        ans += s == t;
    }
    cout << ans << endl;

    return 0;
}