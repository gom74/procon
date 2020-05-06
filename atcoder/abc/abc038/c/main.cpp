#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a.at(i);
    }

    ll ans = 0;
    int right = 0;
    for (int left = 0; left < N; ++left) {
        while (right < N - 1 && a.at(right) < a.at(right + 1)) {
            right++;
        }
        ans += right - left + 1;
        if (left == right) {
            right++;
        }
    }
    cout << ans << endl;

    return 0;
}