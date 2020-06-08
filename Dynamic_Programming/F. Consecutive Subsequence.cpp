#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 5;
int n, st, ans;
int ar[N];
map<int, int> dp;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
    }
    for (int i = 1; i <= n; i++) {
        dp[ar[i]] = 1;
        if(dp[ar[i]-1])
            dp[ar[i]] = max(dp[ar[i]], dp[ar[i] - 1] + 1);
        if (ans < dp[ar[i]]) {
            ans = dp[ar[i]];
            st = ar[i];
        }
    }

    cout << ans << '\n';
    for (int num = st - ans + 1, i = 1; num <= st && i <= n; i++) {
        if (ar[i] == num) {
            cout << i << ' ';
            num++;
        }
    }
    
    return 0;
}