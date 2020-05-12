#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    int N;
    cin >> N;
    vector<double> x(N), y(N);
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> x.at(i) >> y.at(i);
        A.at(i) = i;
    }

    double sum = 0.0;
    int cnt = 0;
    do {
        cnt++;
        for (int i = 1; i < N; ++i) {
            int now = A.at(i), prev = A.at(i - 1);
            double dx = x.at(now) - x.at(prev);
            double dy = y.at(now) - y.at(prev);
            sum += sqrt(dx * dx + dy * dy);
        }
    } while (next_permutation(A.begin(), A.end()));

    cout << sum / cnt << endl;

    return 0;
}