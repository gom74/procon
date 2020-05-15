#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    int cnt0 = 0, cnt4 = 0;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        if (a % 2) {
            cnt0++;
        } else if (a % 4 == 0) {
            cnt4++;
        }
    }

    if (cnt0 + cnt4 == N) {
        cout << ((cnt0 > cnt4 + 1) ? "No" : "Yes") << endl;
    } else {
        cout << ((cnt0 > cnt4) ? "No" : "Yes") << endl;
    }

    return 0;
}