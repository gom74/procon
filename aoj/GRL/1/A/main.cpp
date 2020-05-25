#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

struct edge {
    int to;
    int cost;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int V, E, r;
    cin >> V >> E >> r;
    vector<vector<edge> > G(V);
    for (int i = 0; i < E; ++i) {
        int s, t, d;
        cin >> s >> t >> d;
        G.at(s).push_back(edge{t, d});
    }

    vector<int> d(V, INT_MAX);
    priority_queue<P, vector<P>, greater<P> > que;
    d.at(r) = 0;
    que.push(make_pair(0, r));
    while (!que.empty()) {
        auto p = que.top();
        que.pop();
        int now = p.second;
        if (d.at(now) < p.first) continue;
        for (auto &e : G.at(now)) {
            if (d.at(e.to) > d.at(now) + e.cost) {
                d.at(e.to) = d.at(now) + e.cost;
                que.push(make_pair(d.at(e.to), e.to));
            }
        }
    }

    for (auto &x : d) {
        if (x == INT_MAX) {
            cout << "INF" << endl;
        } else {
            cout << x << endl;
        }
    }

    return 0;
}