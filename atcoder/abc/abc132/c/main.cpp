#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> d(N);
    for (auto &x : d) {
        cin >> x;
    }
    sort(d.begin(), d.end());
    cout << d.at(N / 2) - d.at(N / 2 - 1) << endl;

    return 0;
}