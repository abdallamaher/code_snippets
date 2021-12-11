#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 3e4 + 5;
int n;
int v[] = { 1, 5, 10, 25, 50 };
ll dp[10][N];

ll solve(int i, int rem) {
    if (rem == 0)return 1;
    if (rem < 0 || i == 5)return 0;

    ll& ret = dp[i][rem];
    if (~ret)return ret;

    ll take = solve(i, rem - v[i]);
    ll leave = solve(i + 1, rem);

    return ret = take + leave;
}

int main() {
    // ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    memset(dp, -1, sizeof(dp));
    while (scanf("%d", &n) == 1) {
        if (solve(0, n) != 1)printf("There are %lld ways to produce %d cents change.\n", solve(0, n), n);
        else printf("There is only 1 way to produce %d cents change.\n", n);
    }
    return 0;
}