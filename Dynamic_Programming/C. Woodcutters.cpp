#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
const int N = 1e5 + 5;
ll x[N], h[N];
int dp[N][3][3];

int solve(int i, int pr, int dir) {
    if (i > n)return 0;
    int& ret = dp[i][pr][dir];
    if (~ret)return ret;

    ret = solve(i + 1, 0, 0);
    ll len = 0;
    if (!pr || !dir) len = x[i] - x[i - 1];
    else if (dir) len = x[i] - x[i - 1] - h[i - 1];
    if (len > h[i])ret = max(ret, solve(i + 1, 1, 0) + 1);

    len = x[i + 1] - x[i];
    if (len > h[i])ret = max(ret, solve(i + 1, 1, 1) + 1);

    return ret;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    x[0] = -1e12;
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        x[i] = a, h[i] = b;
    }
    x[n + 1] = 1e12;
    memset(dp, -1, sizeof(dp));
    cout << solve(1, 0, 0);

    return 0;
}