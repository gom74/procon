#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string S;
    cin >> S;
    vector<int> cnt(26, 0);
    for (auto &c : S) {
        cnt.at(c - 'a')++;
    }
    for (auto &x : cnt) {
        if (x % 2) {
            cout << "No" << endl;
            exit(0);
        }
    }
    cout << "Yes" << endl;

    return 0;
}