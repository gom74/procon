#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int H, W;
    cin >> H >> W;
    vector<vector<char> > field(H, vector<char>(W));
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            cin >> field.at(y).at(x);
            if (field.at(y).at(x) == '.') {
                field.at(y).at(x) = '0';
            }
        }
    }

    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            if (field.at(y).at(x) == '#') {
                for (int dy = -1; dy <= 1; ++dy) {
                    for (int dx = -1; dx <= 1; ++dx) {
                        if (dy == 0 && dx == 0) continue;
                        int ny = y + dy;
                        int nx = x + dx;
                        if (ny < 0 || H <= ny) continue;
                        if (nx < 0 || W <= nx) continue;
                        if (field.at(ny).at(nx) != '#') {
                            field.at(ny).at(nx) += 1;
                        }
                    }
                }
            }
        }
    }

    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            cout << field.at(y).at(x);
        }
        cout << endl;
    }

    return 0;
}