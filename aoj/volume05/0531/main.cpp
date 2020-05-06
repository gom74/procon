#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const vector<int> dy = {1, -1, 0, 0};
const vector<int> dx = {0, 0, 1, -1};

int compress(vector<int> &x1, vector<int> &x2, int w) {
    int n = x1.size();
    vector<int> X;
    for (int i = 0; i < n; ++i) {
        for (int d = -1; d <= 1; ++d) {
            int tx1 = x1.at(i) + d;
            int tx2 = x2.at(i) + d;
            if (0 <= tx1 && tx1 < w) X.push_back(tx1);
            if (0 <= tx2 && tx2 < w) X.push_back(tx2);
        }
    }
    sort(X.begin(), X.end());
    X.erase(unique(X.begin(), X.end()), X.end());
    for (int i = 0; i < n; ++i) {
        x1.at(i) = lower_bound(X.begin(), X.end(), x1.at(i)) - X.begin();
        x2.at(i) = lower_bound(X.begin(), X.end(), x2.at(i)) - X.begin();
    }
    return X.size();
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    while (true) {
        int w, h;
        cin >> w >> h;
        if (w == 0 && h == 0) break;
        int n;
        cin >> n;
        vector<int> x1(n), y1(n), x2(n), y2(n);
        for (int i = 0; i < n; ++i) {
            cin >> x1.at(i) >> y1.at(i);
            cin >> x2.at(i) >> y2.at(i);
            x2.at(i)--;
            y2.at(i)--;
        }
        w = compress(x1, x2, w);
        h = compress(y1, y2, h);

        vector<vector<int> > field(h, vector<int>(w, 0));
        for (int i = 0; i < n; ++i) {
            for (int y = y1.at(i); y <= y2.at(i); ++y) {
                for (int x = x1.at(i); x <= x2.at(i); ++x) {
                    field.at(y).at(x) = 1;
                }
            }
        }
        int ans = 0;
        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                if (field.at(y).at(x)) continue;
                ans++;
                queue<pair<int, int> > que;
                que.push(make_pair(y, x));
                while (!que.empty()) {
                    auto p = que.front();
                    que.pop();
                    for (int i = 0; i < 4; ++i) {
                        int ny = p.first + dy.at(i);
                        int nx = p.second + dx.at(i);
                        if (ny < 0 || h <= ny) continue;
                        if (nx < 0 || w <= nx) continue;
                        if (field.at(ny).at(nx)) continue;
                        field.at(ny).at(nx) = 1;
                        que.push(make_pair(ny, nx));
                    }
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}