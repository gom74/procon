#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    vector<vector<int> > G(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        G.at(a - 1).push_back(b - 1);
        G.at(b - 1).push_back(a - 1);
    }
    for (auto &V : G) {
        cout << V.size() << endl;
    }

    return 0;
}