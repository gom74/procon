#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<P> V;
    for (int i = 0; i < N; ++i) {
        int A, B;
        cin >> A >> B;
        V.push_back(make_pair(B, A));
    }
    sort(V.begin(), V.end());

    ll now = 0;
    for (auto &p : V) {
        now += p.second;
        if (now > p.first) {
            cout << "No" << endl;
            exit(0);
        }
    }
    cout << "Yes" << endl;

    return 0;
}