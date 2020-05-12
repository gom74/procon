#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<vector<int> > V(N);
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        a--;
        V.at(i).push_back(a);
        if (find(V.at(a).begin(), V.at(a).end(), i) != V.at(a).end()) {
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}