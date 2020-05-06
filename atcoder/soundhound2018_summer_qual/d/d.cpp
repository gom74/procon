#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

struct edge {
    int to;
    int cost[2];
};

typedef pair<long long, long long> pll;

int n, m, s, t;
vector<vector<edge> > G;
vector<vector<long long> > d(2);  // 0 -> yen, 1 -> snuuk

void dijkstra(int i, int s) {
    priority_queue<pll, vector<pll>, greater<pll> > que;
    d.at(i).at(s) = 0;
    que.push(make_pair(0, s));
    while (!que.empty()) {
        pll p = que.top();
        que.pop();
        int v = p.second;
        if (d.at(i).at(v) < p.first) continue;
        for (auto &e : G.at(v)) {
            if (d.at(i).at(e.to) > d.at(i).at(v) + e.cost[i]) {
                d.at(i).at(e.to) = d.at(i).at(v) + e.cost[i];
                que.push(make_pair(d.at(i).at(e.to), e.to));
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    const long long money = 1e15;
    cin >> n >> m >> s >> t;
    --s;
    --t;
    G.resize(n);
    d.at(0).resize(n, INF);
    d.at(1).resize(n, INF);
    for (int i = 0; i < m; ++i) {
        int u, v, a, b;
        cin >> u >> v >> a >> b;
        --u;
        --v;
        G.at(u).push_back(edge{v, {a, b}});
        G.at(v).push_back(edge{u, {a, b}});
    }
    dijkstra(0, s);
    dijkstra(1, t);
    vector<long long> ans(n, INF);
    ans.at(n - 1) = money - (d.at(0).at(n - 1) + d.at(1).at(n - 1));
    for (int i = n - 2; i >= 0; --i) {
        ans.at(i) = max(ans.at(i + 1), money - (d.at(0).at(i) + d.at(1).at(i)));
    }
    for (auto &x : ans) {
        cout << x << endl;
    }

    return 0;
}