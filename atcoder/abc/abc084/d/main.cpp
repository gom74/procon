#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int Q;
    cin >> Q;
    vector<int> l(Q), r(Q);
    int MAX = 0;
    for (int i = 0; i < Q; ++i) {
        cin >> l.at(i) >> r.at(i);
        MAX = max(MAX, r.at(i));
    }
    vector<bool> is_Prime(MAX + 1, true);
    vector<int> prime;
    vector<int> LNum(MAX + 1, 0);
    if (MAX > 0) is_Prime.at(0) = false;
    if (MAX > 1) is_Prime.at(1) = false;
    for (int i = 2; i <= MAX; ++i) {
        if (is_Prime.at(i)) {
            prime.push_back(i);
            for (int j = 2 * i; j <= MAX; j += i) {
                is_Prime.at(j) = false;
            }
        }
        if (i % 2 == 1 && is_Prime.at(i) && is_Prime.at((i + 1) / 2)) {
            LNum.at(i) = LNum.at(i - 1) + 1;
        } else {
            LNum.at(i) = LNum.at(i - 1);
        }
    }

    for (int i = 0; i < Q; ++i) {
        cout << LNum.at(r.at(i)) - LNum.at(l.at(i) - 1) << endl;
    }

    return 0;
}