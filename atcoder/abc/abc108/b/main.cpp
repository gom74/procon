#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int x_1, y_1, x_2, y_2;
    cin >> x_1 >> y_1 >> x_2 >> y_2;

    int x_3 = x_2 + (y_1 - y_2);
    int y_3 = y_2 + (x_2 - x_1);
    int x_4 = x_1 + (y_1 - y_2);
    int y_4 = y_1 + (x_2 - x_1);

    cout << x_3 << ' ' << y_3 << ' ' << x_4 << ' ' << y_4 << endl;

    /*
    x' = x*cos(T) - y*sin(T)
    y' = x*sin(T) + y*cos(T)
    */

    return 0;
}