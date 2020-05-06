#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<P> V(N);
    for (int i = 0; i < N; ++i) {
        int A;
        cin >> A;
        V.at(i) = make_pair(A, i + 1);
    }
    sort(V.begin(), V.end());
    for (int i = 0; i < N; ++i) {
        if (i) cout << ' ';
        cout << V.at(i).second;
    }
    cout << endl;

    return 0;
}