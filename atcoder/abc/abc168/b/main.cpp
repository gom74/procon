#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int K;
    string S;
    cin >> K >> S;

    if (S.size() <= K) {
        cout << S << endl;
    } else {
        cout << S.substr(0, K) << "..." << endl;
    }

    return 0;
}