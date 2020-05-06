#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const double eps = 1e-10;
const int INF = 1e8;

int a, b, c, d;

double f(double x) {
    return a * pow(x, 3) + b * pow(x, 2) + c * x + d;
}

double df(double x) {
    return 3 * a * pow(x, 2) + 2 * b * x + c;
}

double binary_search(double left, double right, double key) {
    while (true) {
        bool mid = (left + right) / 2;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b >> c >> d;

        int D = b * b - 3 * a * c;
        int ans_n = 0;
        int ans_p = 0;
        if (D >= 0) {
            double x0 = (-1 * b - sqrt(D)) / (3 * a);
            double x1 = (-1 * b + sqrt(D)) / (3 * a);
        }
    }

    return 0;
}