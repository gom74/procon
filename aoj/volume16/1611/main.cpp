#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int N;
vector<int> w;
vector<vector<int> > dp;

int rec(int left = 0, int right = N - 1) {
    if (left == right) {
        return dp.at(left).at(right) = 0;
    }
    if (right - left == 1) {
        return dp.at(left).at(right) = (abs(w.at(left) - w.at(right)) <= 1) ? 2 : 0;
    }
    int &ret = dp.at(left).at(right);
    if (ret != -1) {
        return ret;
    }
    if (rec(left + 1, right - 1) == right - left - 1 && abs(w.at(left) - w.at(right)) <= 1) {
        return ret = right - left + 1;
    }
    for (int i = left; i < right; ++i) {
        ret = max(ret, rec(left, i) + rec(i + 1, right));
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    while (true) {
        cin >> N;
        if (N == 0) break;
        w.resize(N);
        for (int i = 0; i < N; ++i) {
            cin >> w.at(i);
        }

        dp.assign(N, vector<int>(N, -1));

        cout << rec() << endl;
    }

    return 0;
}