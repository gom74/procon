#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    map<int, int> mp;
    for (int i = 0; i < N; ++i) {
        int D;
        cin >> D;
        mp[D]++;
    }
    int M;
    cin >> M;
    for (int i = 0; i < M; ++i) {
        int T;
        cin >> T;
        if (!mp[T]) {
            cout << "NO" << endl;
            exit(0);
        }
        mp[T]--;
    }

    cout << "YES" << endl;

    return 0;
}