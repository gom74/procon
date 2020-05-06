#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
    int N, M;
    cin >> N >> M;
    int killA[N], killB[M];
    int sumA = 0, sumB = 0;
    vector<int> groupA, groupB;
    int res = 1;
    for (int i = 0; i < N; ++i) {
        cin >> killA[i];
        sumA += killA[i];
    }
    for (int i = 0; i < N; ++i) {
        if (i == N - 1) {
            groupA.push_back(res);
            res = 1;
        } else if (killA[i] == killA[i + 1]) {
            ++res;
        } else {
            groupA.push_back(res);
            res = 1;
        }
    }
    for (int i = 0; i < M; ++i) {
        cin >> killB[i];
        sumB += killB[i];
    }
    for (int i = 0; i < M; ++i) {
        if (i == M - 1) {
            groupB.push_back(res);
            res = 1;
        } else if (killB[i] == killB[i + 1]) {
            ++res;
        } else {
            groupB.push_back(res);
            res = 1;
        }
    }
    long long memo[110][1100];
    memset(memo, 0, sizeof(memo));
    for (int i = 1; i <= max(N, M); ++i) {
        for (int j = 0; j <= max(sumA, sumB); ++j) {
            if (i == 1 || j == 0) {
                memo[i][j] = 1;
            } else if (j >= i) {
                memo[i][j] = (memo[i - 1][j] + memo[i][j - i]) % mod;
            } else {
                memo[i][j] = memo[i - 1][j] % mod;
            }
        }
    }
    long long dpA[110][1100], dpB[110][1100];
    memset(dpA, 0, sizeof(dpA));
    memset(dpB, 0, sizeof(dpB));
    dpA[0][0] = 1;
    dpB[0][0] = 1;
    for (int i = 0; i < groupA.size(); ++i) {
        for (int j = 0; j <= sumB; ++j) {
            for (int x = 0; j + x <= sumB; ++x) {
                (dpA[i + 1][j + x] += dpA[i][j] * memo[groupA[i]][x]) %= mod;
            }
        }
    }
    for (int i = 0; i < groupB.size(); ++i) {
        for (int j = 0; j <= sumA; ++j) {
            for (int x = 0; j + x <= sumA; ++x) {
                (dpB[i + 1][j + x] += dpB[i][j] * memo[groupB[i]][x]) %= mod;
            }
        }
    }
    cout << (dpA[groupA.size()][sumB] * dpB[groupB.size()][sumA]) % mod << endl;

    return 0;
}