#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<vector<int> > A(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            cin >> A.at(i).at(j);
        }
    }
    int ans = -1 * 1e8;
    for (int tmp = 0; tmp < pow(3, N); ++tmp) {
        vector<vector<int> > group(3);
        for (int i = 0; i < N; ++i) {
            group.at((int)(tmp / pow(3, i)) % 3).push_back(i);
        }
        int res = 0;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < group.at(i).size(); ++j) {
                for (int k = j + 1; k < group.at(i).size(); ++k) {
                    res += A.at(group.at(i).at(j)).at(group.at(i).at(k));
                }
            }
        }
        ans = max(ans, res);
    }
    cout << ans << endl;

    return 0;
}