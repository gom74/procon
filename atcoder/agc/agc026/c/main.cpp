#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    string S;
    cin >> S;

    string s1 = S.substr(0, N);
    string s2 = S.substr(N, N);
    reverse(s2.begin(), s2.end());
    map<pair<string, string>, ll> mp;

    for (int tmp = 0; tmp < (1 << N); ++tmp) {
        bitset<20> BIT(tmp);
        string a = "";
        string b = "";
        for (int i = 0; i < N; ++i) {
            if (BIT.test(i)) {
                a += s1.at(i);
            } else {
                b += s1.at(i);
            }
        }
        mp[make_pair(a, b)]++;
    }

    ll ans = 0;
    for (int tmp = 0; tmp < (1 << N); ++tmp) {
        bitset<20> BIT(tmp);
        string a = "";
        string b = "";
        for (int i = 0; i < N; ++i) {
            if (BIT.test(i)) {
                a += s2.at(i);
            } else {
                b += s2.at(i);
            }
        }
        ans += mp[make_pair(a, b)];
    }

    cout << ans << endl;

    return 0;
}