#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> prime;
    vector<bool> isPrime(N, true);
    if (N > 0) isPrime.at(0) = false;
    if (N > 1) isPrime.at(1) = false;
    for (int i = 2; i < N; ++i) {
        if (isPrime.at(i)) {
            prime.push_back(i);
            for (int j = 2 * i; j < N; j += i) {
                isPrime.at(j) = false;
            }
        }
    }
    cout << prime.size() << endl;

    return 0;
}