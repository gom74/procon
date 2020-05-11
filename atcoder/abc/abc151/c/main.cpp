#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    vector<int> accepted(N, 0);
    vector<int> wrong(N, 0);
    int ACnum = 0;
    while (M--) {
        int p;
        string S;
        cin >> p >> S;
        p--;
        if (S == "AC") {
            if (accepted.at(p)) continue;
            accepted.at(p) = 1;
            ACnum++;
        } else {
            if (accepted.at(p)) continue;
            wrong.at(p)++;
        }
    }
    int WAnum = 0;
    for (int i = 0; i < N; ++i) {
        if (accepted.at(i)) {
            WAnum += wrong.at(i);
        }
    }
    cout << ACnum << ' ' << WAnum << endl;

    return 0;
}