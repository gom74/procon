#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> V(N);
    int sum = 0;
    for (auto &x : V) {
        cin >> x;
        sum += x;
    }

    if (sum % 10) {
        cout << sum << endl;
        exit(0);
    }
    sort(V.begin(), V.end());
    for (auto &x : V) {
        if (x % 10) {
            sum -= x;
            break;
        }
    }

    cout << ((sum % 10) ? sum : 0) << endl;

    return 0;
}