#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string A, B;
    cin >> A >> B;
    if (A.size() < B.size()) {
        cout << "LESS" << endl;
        exit(0);
    } else if (A.size() > B.size()) {
        cout << "GREATER" << endl;
        exit(0);
    } else {
        for (int i = 0; i < A.size(); ++i) {
            int x = A.at(i) - '0';
            int y = B.at(i) - '0';
            if (x > y) {
                cout << "GREATER" << endl;
                exit(0);
            } else if (x < y) {
                cout << "LESS" << endl;
                exit(0);
            }
        }
        cout << "EQUAL" << endl;
        exit(0);
    }

    return 0;
}