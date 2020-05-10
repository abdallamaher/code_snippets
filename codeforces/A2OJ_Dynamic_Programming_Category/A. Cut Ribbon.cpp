#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long


void brute_force(){
    int n, a, b, c, ans = 0;
    cin >> n >> a >> b >> c;
    for (int i = 0; i <= n; i++) {
        for (int ii = 0; ii <= n; ii++) {
            int t = n - (a * i + b * ii) ;
            if (t>=0 && !(t % c)) {
                ans = max(ans, i + ii + t/c);
            }
        }
    }
    cout << ans;
}

/*
Memo
*/
const int N = 4e3 + 5;
int n, a, b, c, mn;
int dp[N];
int solve(int rem) {
    if (rem == 0)return 0;
    if (rem<0)return -1e8;
    if (~dp[rem])return dp[rem];
    int ans = -1e9;
    ans = max(ans, 1 + solve(rem - a));
    ans = max(ans, 1 + solve(rem - b));
    ans = max(ans, 1 + solve(rem - c));
    return dp[rem] = ans;
}
int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof(dp));
    cin >> n >> a >> b >> c;
    mn = min(a, min(b, c));
    cout << solve(n);
    return 0;
}


/* Table */
int dp[4][N];
int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> a >> b >> c;
    vector<int> v(n+3);
    v[1] = a, v[2] = b, v[3] = c;
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= n; j++) {
            int a, b=0;
            a = dp[i - 1][j];
            if (j>=v[i] && (j == v[i] || dp[i][j - v[i]])) b = dp[i][j - v[i]] + 1;
            dp[i][j] = max(a, b);
        }
    }

    cout << dp[3][n];
    return 0;
}

