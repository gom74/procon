#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;
    vector<int> V(N + 1, 0);
    int div = 0;
    for (int i = 0; i < N; ++i) {
        int A;
        cin >> A;
        if (V.at(A) == 0) div++;
        V.at(A)++;
    }

    sort(V.begin(), V.end());
    int ans = 0;
    for (auto itr = upper_bound(V.begin(), V.end(), 0); itr != V.end(); ++itr) {
        if (div <= K) break;
        ans += *itr;
        div--;
    }

    cout << ans << endl;

    return 0;
}