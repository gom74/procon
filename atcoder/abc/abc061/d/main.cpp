#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e18;

struct edge {
    int from;
    int to;
    int cost;
};

bool BellmanFord(vector<edge> &es, vector<ll> &dist, int V, int s) {
    dist.resize(V, INF);
    dist.at(s) = 0;
    for (int i = 0; i < V; ++i) {
        for (auto &e : es) {
            if (dist.at(e.from) == INF) continue;
            dist.at(e.to) = min(dist.at(e.to), dist.at(e.from) + e.cost);
        }
    }
    for (auto &e : es) {
        if (dist.at(e.from) == INF) continue;
        if (dist.at(e.to) > dist.at(e.from) + e.cost) return false;
    }
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    vector<edge> es;
    for (int i = 0; i < M; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        es.push_back(edge{a - 1, b - 1, -1 * c});
    }
    vector<ll> dist(N, INF);
    dist.at(0) = 0;
    for (int i = 0; i < N; ++i) {
        for (auto &e : es) {
            if (dist.at(e.from) == INF) continue;
            dist.at(e.to) = min(dist.at(e.to), dist.at(e.from) + e.cost);
        }
    }
    ll ans = dist.at(N - 1);
    for (int i = 0; i < N; ++i) {
        for (auto &e : es) {
            if (dist.at(e.from) == INF) continue;
            dist.at(e.to) = min(dist.at(e.to), dist.at(e.from) + e.cost);
        }
    }
    if (dist.at(N - 1) == ans) {
        cout << -1 * ans << endl;
    } else {
        cout << "inf" << endl;
    }

    return 0;
}