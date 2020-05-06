#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, X, Y;
    cin >> N >> X >> Y;

    vector<int> cnt(N, 0);
    for (int i = 1; i <= N; ++i) {
        for (int j = i + 1; j <= N; ++j) {
            int d = min(abs(i - j), min(abs(i - X) + abs(Y - j) + 1, abs(i - Y) + abs(X - j) + 1));
            cnt.at(d)++;
        }
    }

    for (int i = 1; i < N; ++i) {
        cout << cnt.at(i) << endl;
    }

    return 0;
}