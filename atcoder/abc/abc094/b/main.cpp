#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M, X;
    cin >> N >> M >> X;
    int left = 0, right = 0;
    for (int i = 0; i < M; ++i) {
        int A;
        cin >> A;
        if (A < X) {
            left++;
        } else {
            right++;
        }
    }
    cout << min(left, right) << endl;

    return 0;
}