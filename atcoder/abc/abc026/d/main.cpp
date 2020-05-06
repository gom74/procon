#include <bits/stdc++.h>
using namespace std;
using ll = long long;

double f(int A, int B, int C, double t) {
    return A * t + B * sin(C * t * M_PI);
}

bool check(int A, int B, int C, double t) {
    return abs(f(A, B, C, t) - 100.0) <= 1e-6;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int A, B, C;
    cin >> A >> B >> C;

    double left = 0.0;
    double right = 220.0;
    while (true) {
        double mid = (left + right) / 2;
        if (check(A, B, C, mid)) {
            cout << mid << endl;
            return 0;
        }
        if (f(A, B, C, mid) > 100) {
            right = mid;
        } else {
            left = mid;
        }
    }

    return 0;
}