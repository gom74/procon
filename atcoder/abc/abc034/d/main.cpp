#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const double eps = 1e-10;

bool check(ll N, ll K, vector<double> &salt, vector<double> &water, double X) {
    vector<double> V(N);
    for (int i = 0; i < N; ++i) {
        V.at(i) = salt.at(i) - water.at(i) * X;
    }
    sort(V.begin(), V.end(), greater<double>());
    double sum = 0.0;
    for (int i = 0; i < K; ++i) {
        sum += V.at(i);
    }
    return sum >= 0;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cout << fixed << setprecision(9);

    ll N, K;
    cin >> N >> K;
    vector<double> water(N);
    vector<double> salt(N);
    for (int i = 0; i < N; ++i) {
        double w, p;
        cin >> w >> p;
        water.at(i) = w;
        salt.at(i) = w * p;
    }
    double left = -1;
    double right = 110;
    while (right - left > eps) {
        double mid = (left + right) / 2;
        if (check(N, K, salt, water, mid)) {
            left = mid;
        } else {
            right = mid;
        }
    }

    cout << left << endl;

    return 0;
}