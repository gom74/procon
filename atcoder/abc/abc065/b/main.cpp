#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> A(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> A.at(i);
    }

    vector<int> used(N + 1, 0);
    int pnt = 1;
    int cnt = 0;
    while (true) {
        cnt++;
        if (used.at(A.at(pnt))) {
            cout << -1 << endl;
            break;
        }
        if (A.at(pnt) == 2) {
            cout << cnt << endl;
            break;
        }
        used.at(pnt) = 1;
        pnt = A.at(pnt);
    }

    return 0;
}