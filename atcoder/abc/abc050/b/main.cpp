#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> T(N);
    int sum = 0;
    for (auto &x : T) {
        cin >> x;
        sum += x;
    }
    int M;
    cin >> M;
    for (int i = 0; i < M; ++i) {
        int P, X;
        cin >> P >> X;
        cout << sum - T.at(P - 1) + X << endl;
    }

    return 0;
}