#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    int sum = 0;
    for (auto &a : A) {
        cin >> a;
        sum += a;
    }
    sort(A.begin(), A.end(), greater<int>());
    cout << ((A.at(M - 1) * 4 * M >= sum) ? "Yes" : "No") << endl;

    return 0;
}