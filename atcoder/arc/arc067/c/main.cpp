#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> prime;
    vector<bool> isPrime(N + 1, true);
    isPrime.at(0) = false;
    isPrime.at(1) = false;
    for (int i = 2; i <= N; ++i) {
        if (isPrime.at(i)) {
            prime.push_back(i);
            for (int j = 2 * i; j <= N; j += i) {
                isPrime.at(j) = false;
            }
        }
    }

    vector<ll> cnt(prime.size(), 0);
    for (int x = 1; x <= N; ++x) {
        int num = x;
        for (int i = 0; i < prime.size(); ++i) {
            while (num % prime.at(i) == 0) {
                num /= prime.at(i);
                ++cnt.at(i);
            }
        }
    }
    ll ans = 1;
    for (auto &x : cnt) {
        ans = ans * (x + 1) % MOD;
    }
    cout << ans << endl;

    return 0;
}