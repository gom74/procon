#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    map<int, int> mp;
    for (int i = 0; i < N; ++i) {
        int A;
        cin >> A;
        mp[A]++;
    }
    if (mp.size() == N) {
        cout << "Correct" << endl;
        return 0;
    }
    int from, to;
    for (int i = 1; i <= N; ++i) {
        if (mp[i] == 2) from = i;
        if (mp[i] == 0) to = i;
    }
    cout << from << ' ' << to << endl;

    return 0;
}