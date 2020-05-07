#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int getSum(int X) {
    int res = 0;
    while (X) {
        res += X % 10;
        X /= 10;
    }
    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, A, B;
    cin >> N >> A >> B;
    int ans = 0;
    for (int n = 1; n <= N; ++n) {
        int x = getSum(n);
        if (A <= x && x <= B) {
            ans += n;
        }
    }
    cout << ans << endl;

    return 0;
}