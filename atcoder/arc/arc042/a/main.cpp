#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    vector<int> V;
    for (int i = N; i > 0; --i) {
        V.push_back(i);
    }
    for (int i = 0; i < M; ++i) {
        int a;
        cin >> a;
        V.push_back(a);
    }
    vector<int> seen(N + 1, 0);
    int cnt = 0;
    for (int i = V.size() - 1; i >= 0; --i) {
        if (cnt == N) break;
        if (seen.at(V.at(i))) continue;
        cout << V.at(i) << endl;
        seen.at(V.at(i))++;
        cnt++;
    }

    return 0;
}