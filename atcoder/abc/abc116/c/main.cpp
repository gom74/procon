#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int N;
vector<int> h;
queue<P> que;

void nextPair(int l, int r) {
    int nl = l;
    for (int nr = nl; nr <= r; ++nr) {
        if (h.at(nr) == 0) {
            if (nr != nl) {
                que.push(make_pair(nl, nr - 1));
            }
            nl = nr + 1;
        }
    }
    if (nl <= r) {
        que.push(make_pair(nl, r));
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    h.resize(N);
    for (auto &x : h) cin >> x;

    int ans = 0;
    nextPair(0, N - 1);
    while (!que.empty()) {
        auto p = que.front();
        que.pop();
        int l = p.first, r = p.second;
        int minh = INT_MAX;
        for (int i = l; i <= r; ++i) {
            minh = min(minh, h.at(i));
        }
        ans += minh;
        for (int i = l; i <= r; ++i) {
            h.at(i) -= minh;
        }
        nextPair(l, r);
    }

    cout << ans << endl;

    return 0;
}