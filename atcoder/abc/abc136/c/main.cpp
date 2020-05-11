#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<ll> H(N);
    for (auto &x : H) cin >> x;

    for (int i = N - 2; i >= 0; --i) {
        if (H.at(i) - H.at(i + 1) == 1) {
            H.at(i)--;
        } else if (H.at(i) - H.at(i + 1) > 1) {
            cout << "No" << endl;
            exit(0);
        }
    }
    cout << "Yes" << endl;

    return 0;
}