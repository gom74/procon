#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

vector<char> b;

bool comp(string s, string t) {
    if (s.size() != t.size()) {
        return s.size() < t.size();
    } else {
        for (int i = 0; i < s.size(); ++i) {
            int p = find(b.begin(), b.end(), s.at(i)) - b.begin();
            int q = find(b.begin(), b.end(), t.at(i)) - b.begin();
            if (p == q) continue;
            return p < q;
        }
        return true;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    b.resize(10);
    for (auto &x : b) cin >> x;
    int N;
    cin >> N;
    vector<string> a(N);
    for (auto &x : a) cin >> x;
    sort(a.begin(), a.end(), comp);
    for (auto &x : a) cout << x << endl;

    return 0;
}