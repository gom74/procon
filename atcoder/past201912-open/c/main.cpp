#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    vector<int> V(6);
    for (int i = 0; i < 6; ++i) {
        cin >> V.at(i);
    }
    sort(V.begin(), V.end(), greater<int>());
    cout << V.at(2) << endl;

    return 0;
}