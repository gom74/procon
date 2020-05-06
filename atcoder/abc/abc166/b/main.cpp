#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;
    map<int, int> mp;
    for (int i = 0; i < K; ++i) {
        int d;
        cin >> d;
        for (int j = 0; j < d; ++j) {
            int A;
            cin >> A;
            mp[A]++;
        }
    }
    cout << N - mp.size() << endl;

    return 0;
}