#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    map<ll, int> mp;
    for (int i = 0; i < N; ++i) {
        int A;
        cin >> A;
        mp[A]++;
    }

    int cnt = 0;
    ll ans = 1;
    for (auto itr = mp.rbegin(); itr != mp.rend(); ++itr) {
        if (itr->second >= 4 && cnt == 0) {
            ans = itr->first * itr->first;
            cnt = 2;
            break;
        } else if (itr->second >= 2) {
            ans *= itr->first;
            cnt++;
            if (cnt == 2) break;
        }
    }

    cout << ((cnt == 2) ? ans : 0LL) << endl;

    return 0;
}