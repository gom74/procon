#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<string> W(N);
    map<string, int> mp;
    for (int i = 0; i < N; ++i) {
        cin >> W.at(i);
        if (mp[W.at(i)]) {
            cout << "No" << endl;
            exit(0);
        }
        mp[W.at(i)]++;
        if (i == 0) continue;
        if (W.at(i - 1).at(W.at(i - 1).size() - 1) != W.at(i).at(0)) {
            cout << "No" << endl;
            exit(0);
        }
    }
    cout << "Yes" << endl;

    return 0;
}