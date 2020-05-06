#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    map<int, int> mp;
    int cnt = 0;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        if (a >= 3200) {
            cnt++;
        } else {
            mp[a / 400]++;
        }
    }
    int res = mp.size();
    cout << max(1, res) << ' ' << res + cnt << endl;

    return 0;
}