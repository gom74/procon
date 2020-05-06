#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    map<string, int> mp;
    for (int i = 0; i < N; ++i) {
        string S;
        cin >> S;
        mp[S]++;
    }
    cout << mp.size() << endl;

    return 0;
}