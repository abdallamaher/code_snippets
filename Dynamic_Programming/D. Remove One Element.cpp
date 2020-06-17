#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, st, ans;
int ar[1 << 19];
int dp[1 << 19][3];

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (ar[i] > ar[i - 1])
            dp[i][0] = dp[i - 1][0] + 1;
        else 
            dp[i][0] = 1;

        ans = max(ans, dp[i][0]);
    }

    for (int i = n; i >= 1; i--) {
        if (ar[i] < ar[i + 1])
            dp[i][1] = dp[i + 1][1] + 1;
        else 
            dp[i][1] = 1;
    }

    for (int i = 1; i <= n; i++) {
        if (ar[i + 1] > ar[i - 1])
            ans = max(ans, dp[i - 1][0] + dp[i + 1][1]);
    }
    cout << ans;
    return 0;
}

