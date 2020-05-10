#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

bool comp(pair<int, string> a, pair<int, string> b) {
    if (a.first != b.first) {
        return a.first > b.first;
    } else {
        return a.second < b.second;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    map<string, int> mp;
    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        mp[s]++;
    }
    vector<pair<int, string> > V;
    for (auto &p : mp) {
        V.push_back(make_pair(p.second, p.first));
    }
    sort(V.begin(), V.end(), comp);
    for (int i = 0; i < V.size(); ++i) {
        cout << V.at(i).second << endl;
        if (i == V.size() - 1 || V.at(i).first > V.at(i + 1).first) {
            break;
        }
    }

    return 0;
}