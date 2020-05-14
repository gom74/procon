#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, Q;
    cin >> N >> Q;
    vector<vector<int> > tree(N);
    vector<ll> cnt(N, 0);
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        tree.at(a - 1).push_back(b - 1);
        tree.at(b - 1).push_back(a - 1);
    }

    for (int i = 0; i < Q; ++i) {
        int p;
        ll x;
        cin >> p >> x;
        cnt.at(p - 1) += x;
    }
    queue<int> que;
    vector<int> used(N, 0);
    que.push(0);
    while (!que.empty()) {
        int p = que.front();
        que.pop();
        used.at(p) = 1;
        for (auto &np : tree.at(p)) {
            if (used.at(np)) continue;
            cnt.at(np) += cnt.at(p);
            que.push(np);
        }
    }

    for (int i = 0; i < N; ++i) {
        if (i) cout << ' ';
        cout << cnt.at(i);
    }
    cout << endl;

    return 0;
}