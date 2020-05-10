#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    int left = 0, right = 0;
    for (int i = 0; i < N; ++i) {
        string S;
        cin >> S;
        if (S.front() == ')') left++;
        if (S.back() == '(') right++;
        int cnt1 = 0, cnt2 = 0;
        for (int j = 0; j < S.size(); ++j) {
            if (j == 0 && S.at(j) == ')') continue;
            if (j == S.size() - 1 && S.at(j) == '(') continue;
            if (S.at(j) == '(') cnt1++;
            if (S.at(j) == ')') cnt2++;
        }
        if (cnt1 > cnt2) {
            right += cnt1 - cnt2;
        } else {
            left += cnt2 - cnt1;
        }
    }
    cout << ((right == left) ? "Yes" : "No") << endl;

    return 0;
}