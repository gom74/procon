#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> LIS(N, INT_MAX);
    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        *lower_bound(LIS.begin(), LIS.end(), x) = x;
    }

    cout << N - (lower_bound(LIS.begin(), LIS.end(), INT_MAX) - LIS.begin()) << endl;

    return 0;
}