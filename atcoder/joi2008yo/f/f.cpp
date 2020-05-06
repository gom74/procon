#include <bits/stdc++.h>
using namespace std;

using P = pair<long long, int>;
const long long INF = 1e18;

struct edge {
    int to;
    long long cost;
};

int n, k;
vector<vector<edge> > G;
vector<long long> dist;

void dijkstra(int s) {
    priority_queue<P, vector<P>, greater<P> > que;
    dist.clear();
    dist.resize(n, INF);
    dist.at(s) = 0;
    que.push(make_pair(0, s));
    while (!que.empty()) {
        auto p = que.top();
        que.pop();
        int v = p.second;
        if (dist.at(v) < p.first) continue;
        for (auto &e : G.at(v)) {
            if (dist.at(e.to) > dist.at(v) + e.cost) {
                dist.at(e.to) = dist.at(v) + e.cost;
                que.push(make_pair(dist.at(e.to), e.to));
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> k;
    G.resize(n);
    while (k--) {
        int order;
        cin >> order;
        if (order == 0) {
            int a, b;
            cin >> a >> b;
            --a;
            --b;
            dijkstra(a);
            cout << ((dist.at(b) != INF) ? dist.at(b) : -1) << endl;
        } else if (order == 1) {
            int c, d, e;
            cin >> c >> d >> e;
            --c;
            --d;
            G.at(c).push_back(edge{d, e});
            G.at(d).push_back(edge{c, e});
        }
    }

    return 0;
}