#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF = 1e18;

int N, M;
vector<vector<P> > dist;
vector<vector<P> > dp;

P rec(int S = (1 << N) - 1, int to = 0) {
    if (S == 0) {
        return (to) ? make_pair(INF, 0LL) : make_pair(0LL, 1LL);
    }
    if (!(S & (1 << to))) {
        return make_pair(INF, 0LL);
    }

    auto &ret = dp.at(S).at(to);
    if (ret.first != -1LL) {
        return ret;
    }
    ret = make_pair(INF, 0LL);
    for (int from = 0; from < N; ++from) {
        auto p = rec(S ^ (1 << to), from);
        p.first += dist.at(from).at(to).first;
        if (p.first <= dist.at(from).at(to).second) {
            if (p.first < ret.first) {
                ret = p;
            } else if (p.first == ret.first) {
                ret.second += p.second;
            }
        }
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    dist.assign(N, vector<P>(N, make_pair(INF, 0)));
    for (int i = 0; i < M; ++i) {
        ll s, t, d, time;
        cin >> s >> t >> d >> time;
        s--, t--;
        dist.at(s).at(t) = make_pair(d, time);
        dist.at(t).at(s) = make_pair(d, time);
    }
    dp.assign((1 << N), vector<P>(N, make_pair(-1LL, 0LL)));

    auto ans = rec();
    if (ans.first == INF) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << ans.first << ' ' << ans.second << endl;
    }

    return 0;
}