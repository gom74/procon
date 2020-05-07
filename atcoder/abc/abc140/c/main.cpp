#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> A(N, INT_MAX);
    for (int i = 0; i < N - 1; ++i) {
        int B;
        cin >> B;
        A.at(i) = min(A.at(i), B);
        A.at(i + 1) = B;
    }
    int sum = 0;
    for (auto &x : A) {
        sum += x;
    }
    cout << sum << endl;

    return 0;
}