#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int N;
vector<ll> A;
vector<vector<ll> > dp;

ll rec(int left, int right, int ioiturn = 1) {
    if (dp.at(left).at(right) != -1) {
        return dp.at(left).at(right);
    }
    if (left == right) {
        return dp.at(left).at(right) = (ioiturn) ? 0 : A.at(left);
    }
    int nextl = (left + 1) % N;
    int nextr = (right - 1 + N) % N;
    if (ioiturn) {
        if (A.at(left) > A.at(right)) {
            return dp.at(left).at(right) = rec(nextl, right, 0);
        } else {
            return dp.at(left).at(right) = rec(left, nextr, 0);
        }
    }
    return dp.at(left).at(right) = max(rec(nextl, right) + A.at(left), rec(left, nextr) + A.at(right));
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    A.resize(N);
    for (auto &x : A) {
        cin >> x;
    }

    ll ans = 0;
    dp.assign(N, vector<ll>(N, -1));
    for (int x = 0; x < N; ++x) {
        int left = (x + 1) % N;
        int right = (x - 1 + N) % N;
        ans = max(ans, rec(left, right) + A.at(x));
    }

    cout << ans << endl;

    return 0;
}