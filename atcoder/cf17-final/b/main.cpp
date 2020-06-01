#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string S;
    cin >> S;

    vector<int> cnt(3, 0);
    for (auto &c : S) {
        cnt.at(c - 'a')++;
    }

    if (max(abs(cnt.at(0) - cnt.at(1)), max(abs(cnt.at(1) - cnt.at(2)), abs(cnt.at(2) - cnt.at(0)))) <= 1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}