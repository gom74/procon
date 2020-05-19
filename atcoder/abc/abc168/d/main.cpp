#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    vector<vector<int> > G(N + 1);
    for (int i = 0; i < M; ++i) {
        int A, B;
        cin >> A >> B;
        G.at(A).push_back(B);
        G.at(B).push_back(A);
    }
    vector<int> ans(N + 1, INT_MAX);
    vector<int> dist(N + 1, INT_MAX);
    dist.at(1) = 0;
    queue<int> que;
    que.push(1);
    while (!que.empty()) {
        auto p = que.front();
        que.pop();
        for (auto &x : G.at(p)) {
            if (dist.at(x) > dist.at(p) + 1) {
                dist.at(x) = dist.at(p) + 1;
                ans.at(x) = p;
                que.push(x);
            }
        }
    }
    for (int i = 2; i <= N; ++i) {
        if (ans.at(i) == INT_MAX) {
            cout << "No" << endl;
            exit(0);
        }
    }
    cout << "Yes" << endl;
    for (int i = 2; i <= N; ++i) {
        cout << ans.at(i) << endl;
    }

    return 0;
}