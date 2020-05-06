#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    for (int i = 0; i < s.size(); ++i) {
        if (s.at(i) - '0' < 0 || 9 < s.at(i) - '0') {
            cout << "error" << endl;
            return 0;
        }
    }
    cout << 2 * stoi(s) << endl;

    return 0;
}
