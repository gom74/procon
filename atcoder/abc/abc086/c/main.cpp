#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> t(N + 1), x(N + 1), y(N + 1);
    t.at(0) = 0, x.at(0) = 0, y.at(0) = 0;
    for (int i = 1; i <= N; ++i) {
        cin >> t.at(i) >> x.at(i) >> y.at(i);
    }

    for (int i = 1; i <= N; ++i) {
        if (t.at(i) % 2 != (x.at(i) + y.at(i)) % 2) {
            cout << "No" << endl;
            exit(0);
        }
        int d = abs(x.at(i) - x.at(i - 1)) + abs(y.at(i) - y.at(i - 1));
        if (d > t.at(i) - t.at(i - 1)) {
            cout << "No" << endl;
            exit(0);
        }
    }
    cout << "Yes" << endl;

    return 0;
}