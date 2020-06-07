#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int t, n, p, k, ans;
int ar[(int)2e5 + 5];
int dp[(int)2e5 + 5];

int solve(int i) {
    if (i < 1)return 0;
    if (~dp[i])
        return dp[i];

    int a = solve(i - 1) + ar[i];
    int b = 1e7;
    if(i-k >= 0) 
        b = solve(i - k) + ar[i];

    return dp[i] = min(a, b);
}
int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> p >> k;
        for (int i = 1; i <= n; i++) {
            cin >> ar[i];
        }
        sort(ar+1, ar + n+1);
        memset(dp, -1, sizeof(dp));
        ans = 0;
        for (int i = 1; i <= n; i++) {
            //printf("%d %d\n", i, solve(i));
            if (solve(i) <= p)
                ans = i;
        }
        cout << ans << '\n';
    }
    return 0;
}

void Table() {
    cin >> t;
    while (t--) {
        cin >> n >> p >> k;
        for (int i = 1; i <= n; i++) {
            cin >> ar[i];
        }
        sort(ar, ar + n + 1);
        int ans = 0;
        for (int i = 1; i < k; i++) {
            dp[i] = dp[i-1] + ar[i];
            if (dp[i] <= p)
                ans = i;
        }
        for (int i = k; i <= n; i++) {
            dp[i] = dp[i - k] + ar[i];
            if(dp[i] <= p)
                ans = i;
        }
        cout << ans << '\n';
    }
}