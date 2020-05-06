#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, Q;
    cin >> N >> Q;
    vector<vector<char> > follow(N, vector<char>(N, 'N'));
    for (int i = 0; i < Q; ++i) {
        int opr, a, b;
        cin >> opr;
        if (opr == 1) {
            cin >> a >> b;
            follow.at(a - 1).at(b - 1) = 'Y';
        } else if (opr == 2) {
            cin >> a;
            for (int i = 0; i < N; ++i) {
                if (follow.at(i).at(a - 1) == 'Y') {
                    follow.at(a - 1).at(i) = 'Y';
                }
            }
        } else if (opr == 3) {
            cin >> a;
            vector<char> V = follow.at(a - 1);
            for (int i = 0; i < N; ++i) {
                if (follow.at(a - 1).at(i) == 'Y') {
                    for (int j = 0; j < N; ++j) {
                        if (follow.at(i).at(j) == 'Y' && j != a - 1) {
                            V.at(j) = 'Y';
                        }
                    }
                }
            }
            follow.at(a - 1) = V;
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << follow.at(i).at(j);
        }
        cout << endl;
    }

    return 0;
}