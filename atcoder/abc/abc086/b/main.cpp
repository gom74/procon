#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string a, b;
    cin >> a >> b;
    int num = stoi(a + b);
    int x = sqrt(num);
    cout << ((x * x == num) ? "Yes" : "No") << endl;

    return 0;
}