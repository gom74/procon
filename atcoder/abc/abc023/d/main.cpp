#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool check(ll N, vector<ll> &H, vector<ll> &S, ll X) {
    vector<ll> L(N);
    for (int i = 0; i < N; ++i) {
        if (X < H.at(i)) return false;
        L.at(i) = (X - H.at(i)) / S.at(i);
    }
    sort(L.begin(), L.end());
    for (int i = 0; i < N; ++i) {
        if (L.at(i) < i) return false;
    }
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N;
    cin >> N;
    vector<ll> H(N), S(N);
    for (int i = 0; i < N; ++i) {
        cin >> H.at(i) >> S.at(i);
    }

    ll left = 0;
    ll right = 1e18;
    while (right - left > 1) {
        ll mid = (left + right) / 2;
        (check(N, H, S, mid)) ? (right = mid) : (left = mid);
    }
    cout << right << endl;

    return 0;
}