#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    double A, B, H, M;
    cin >> A >> B >> H >> M;

    double X1 = A * cos(2 * M_PI * (H * 60 + M) / (12 * 60));
    double Y1 = A * sin(2 * M_PI * (H * 60 + M) / (12 * 60));
    double X2 = B * cos(2 * M_PI * M / 60);
    double Y2 = B * sin(2 * M_PI * M / 60);

    cout << sqrt(pow(X1 - X2, 2) + pow(Y1 - Y2, 2)) << endl;

    return 0;
}