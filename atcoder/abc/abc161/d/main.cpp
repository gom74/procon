#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int K;
    cin >> K;

    queue<ll> que;
    for (int i = 1; i <= 9; ++i) {
        que.push(i);
    }
    while (--K) {
        auto x = que.front();
        que.pop();
        if (x % 10 != 0) {
            que.push(10 * x + x % 10 - 1);
        }
        que.push(10 * x + x % 10);
        if (x % 10 != 9) {
            que.push(10 * x + x % 10 + 1);
        }
    }
    cout << que.front() << endl;

    return 0;
}