#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
const int N = 3e3 + 5;
int s[N], c[N];
ll dp[3][N][N];
ll solve(int rem, int i, int p) {
    if (rem == 3)return 0;
    if (i > n)return 1e17;
    ll& ret = dp[rem][i][p];
    if (~ret)return ret;

    ret = solve(rem, i + 1, p);
    if (s[i] > s[p])
        ret = min(ret, solve(rem + 1, i + 1, i) + c[i]);
    return ret;
}
int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    memset(dp, -1, sizeof dp);

    cout << (solve(0, 0, 0) == 1e17 ? -1 : solve(0, 0, 0));
    return 0;
}
