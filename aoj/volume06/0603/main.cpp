#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A.at(i);
    }

    vector<int> V;
    int right = 0;
    for (int left = 0; left < N;) {
        while (right < N && A.at(right) == (A.at(left) + right - left) % 2) {
            right++;
        }
        V.push_back(right - left);
        left = right;
    }

    int ans = 0;
    for (int i = 0; i < V.size(); ++i) {
        int res = V.at(i);
        if (i >= 1) res += V.at(i - 1);
        if (i >= 2) res += V.at(i - 2);
        ans = max(ans, res);
    }
    cout << ans << endl;

    return 0;
}