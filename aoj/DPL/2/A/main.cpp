#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const int INF = 1e9;

int V, E;
vector<vector<int> > dist;
vector<vector<int> > dp;

int rec(int S = (1 << V) - 1, int to = 0) {
    if (S == 0) {
        return (to) ? INF : 0;
    }
    if (!(S & (1 << to))) {
        return INF;
    }
    int &ret = dp.at(S).at(to);
    if (ret != -1) {
        return ret;
    }
    ret = INF;
    for (int from = 0; from < V; ++from) {
        ret = min(ret, rec(S ^ (1 << to), from) + dist.at(from).at(to));
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> V >> E;
    dist.assign(V, vector<int>(V, INF));
    for (int i = 0; i < E; ++i) {
        int s, t, d;
        cin >> s >> t >> d;
        dist.at(s).at(t) = d;
    }

    dp.resize(1 << V, vector<int>(V, -1));
    int ans = rec();

    cout << ((ans == INF) ? -1 : ans) << endl;

    return 0;
}