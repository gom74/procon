#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

ll N, A, B, C;
vector<char> V;
vector<string> S;

void dfs(ll idx, ll a, ll b, ll c) {
    if (idx == N) {
        cout << "Yes" << endl;
        for (auto &x : V) {
            cout << x << endl;
        }
        exit(0);
    }
    if (S.at(idx) == "AB") {
        if (b) {
            V.at(idx) = 'A';
            dfs(idx + 1, a + 1, b - 1, c);
        }
        if (a) {
            V.at(idx) = 'B';
            dfs(idx + 1, a - 1, b + 1, c);
        }
    } else if (S.at(idx) == "AC") {
        if (c) {
            V.at(idx) = 'A';
            dfs(idx + 1, a + 1, b, c - 1);
        }
        if (a) {
            V.at(idx) = 'C';
            dfs(idx + 1, a - 1, b, c + 1);
        }
    } else {
        if (c) {
            V.at(idx) = 'B';
            dfs(idx + 1, a, b + 1, c - 1);
        }
        if (b) {
            V.at(idx) = 'C';
            dfs(idx + 1, a, b - 1, c + 1);
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> A >> B >> C;
    S.resize(N);
    for (auto &x : S) {
        cin >> x;
    }
    V.resize(N);
    dfs(0, A, B, C);
    cout << "No" << endl;

    return 0;
}