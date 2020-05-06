#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string S;
    cin >> S;
    vector<pair<string, string> > V;
    for (int i = 0; i < S.size();) {
        int from, length;
        if ('A' <= S.at(i) && S.at(i) <= 'Z') {
            from = i;
            do {
                ++i;
            } while (i < S.size() && 'a' <= S.at(i) && S.at(i) <= 'z');
            length = i - from + 1;
            string s = S.substr(from, length);
            string t = s;
            for (int j = 0; j < t.size(); ++j) {
                t.at(j) = tolower(t.at(j));
            }
            V.push_back(make_pair(t, s));
        }
        ++i;
    }
    sort(V.begin(), V.end());
    for (int i = 0; i < V.size(); ++i) {
        cout << V.at(i).second;
    }
    cout << endl;

    return 0;
}