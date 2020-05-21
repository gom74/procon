#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const int MOD = 10007;

int N;
vector<int> member;
vector<vector<int> > dp;

int rec(int S, int day) {
    int &ret = dp.at(S).at(day);
    if (!(S & (1 << member.at(day)))) {
        return ret = 0;
    }
    if (day == 0) {
        return ret = S & 1;
    }
    if (ret != -1) {
        return ret;
    }
    ret = 0;
    for (int tmp = 0; tmp < 8; ++tmp) {
        if ((tmp & S) == 0) {
            continue;
        }
        ret = (ret + rec(tmp, day - 1)) % MOD;
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    member.resize(N);
    string s;
    cin >> s;
    for (int i = 0; i < N; ++i) {
        switch (s.at(i)) {
            case 'J':
                member.at(i) = 0;
                break;
            case 'O':
                member.at(i) = 1;
                break;
            case 'I':
                member.at(i) = 2;
                break;
        }
    }

    dp.assign(8, vector<int>(N, -1));
    int ans = 0;
    for (int S = 0; S < 8; ++S) {
        ans = (ans + rec(S, N - 1)) % MOD;
    }

    cout << ans << endl;

    return 0;
}