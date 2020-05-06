#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF = 1e18;

struct edge {
    ll to;
    ll cost;
};

template <class T>
vector<T> dijkstra(T s, T sz, vector<vector<edge> > &G) {
    priority_queue<P, vector<P>, greater<P> > que;
    vector<T> d(sz, INF);
    d.at(s) = 0;
    que.push(make_pair(0, s));
    while (!que.empty()) {
        P p = que.top();
        que.pop();
        int v = p.second;
        if (d.at(v) < p.first) continue;
        for (auto &e : G.at(v)) {
            if (d.at(e.to) > d.at(v) + e.cost) {
                d.at(e.to) = d.at(v) + e.cost;
                que.push(make_pair(d.at(e.to), e.to));
            }
        }
    }
    return d;
}