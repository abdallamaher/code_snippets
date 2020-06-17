#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
int ar[110];
int dp[110][5];

int solve(int i, int p) {
    if (i == n)return 0;
    int& ret = dp[i][p];
    if (~ret)return ret;

    ret = solve(i + 1, 0);
    for (int j = 1; j < 3; j++) {
        if (p == j || (j != ar[i] && ar[i]!=3))continue;
        ret = max(solve(i + 1, j) + 1, ret);
    }
    return ret;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << n - solve(0, 0) << '\n';
    return 0;
}

