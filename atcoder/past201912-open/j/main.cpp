#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF = 1e18;

vector<int> dy = {1, 0, -1, 0};
vector<int> dx = {0, 1, 0, -1};

struct edge {
    ll to;
    ll cost;
};

vector<ll> dijkstra(int s, int H, int W, vector<vector<edge> > &G) {
    priority_queue<P, vector<P>, greater<P> > que;
    vector<ll> d(H * W, INF);
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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int H, W;
    cin >> H >> W;
    vector<ll> A(H * W);
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A.at(i * W + j);
        }
    }
    vector<vector<edge> > G(H * W);
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            for (int i = 0; i < 4; ++i) {
                int ny = y + dy.at(i);
                int nx = x + dx.at(i);
                if (ny < 0 || H <= ny) continue;
                if (nx < 0 || W <= nx) continue;
                G.at(y * W + x).push_back(edge{ny * W + nx, A.at(ny * W + nx)});
                G.at(ny * W + nx).push_back(edge{y * W + x, A.at(y * W + x)});
            }
        }
    }

    auto d1 = dijkstra((H - 1) * W, H, W, G);
    auto d2 = dijkstra((H - 1) * W + (W - 1), H, W, G);
    auto d3 = dijkstra(W - 1, H, W, G);

    ll ans = INF;
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            int p = y * W + x;
            ans = min(ans, d1.at(p) + d2.at(p) + d3.at(p) - 2 * A.at(p));
        }
    }

    cout << ans << endl;

    return 0;
}