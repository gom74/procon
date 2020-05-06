#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> A(N);
    set<int> st;
    for (int i = 0; i < N; ++i) {
        cin >> A.at(i);
        st.insert(A.at(i));
    }

    int ans = 0;
    int right = 0;
    map<int, int> mp;
    for (int left = 0; left < N; ++left) {
        while (right < N && mp[A.at(right)] == 0) {
            mp[A.at(right)]++;
            right++;
        }
        ans = max(ans, right - left);
        if (left == right) {
            right++;
        } else {
            mp[A.at(left)]--;
        }
    }
    cout << ans << endl;

    return 0;
}