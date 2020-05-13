#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const double eps = 1e-10;

double getTime(double P, double Y) {
    return Y + P / pow(2.0, Y / 1.5);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    double P;
    cin >> P;

    double left = 0.0, right = P;
    while (right - left > eps) {
        double mid_left = (right + 2 * left) / 3;
        double mid_right = (2 * right + left) / 3;
        if (getTime(P, mid_left) < getTime(P, mid_right)) {
            right = mid_right;
        } else {
            left = mid_left;
        }
    }

    cout << fixed << setprecision(10) << getTime(P, left) << endl;

    return 0;
}