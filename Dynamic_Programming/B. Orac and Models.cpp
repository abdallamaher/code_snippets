#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int q, n, ans;
const int  N = 1e5 + 5;
int ar[N];
int dp[N];

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> q;
    while (q--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> ar[i];
        }
        for (int i = 1; i <= n; i++) {
            dp[i] = 1;
            for (int j = 1; j * j <= i; j++) {
                if (i % j == 0) {
                    if(ar[i] > ar[j])
                        dp[i] = max(dp[i], dp[j] + 1);
                    //printf("*** %d %d %d %d\n", i, i / j != j, i/j, dp[i / j]);
                    if (i / j != j && ar[i] > ar[i/j])
                        dp[i] = max(dp[i], dp[i / j] + 1);
                }
            }
            //cout << dp[i] << ' ';
            ans = max(ans, dp[i]);
        }
        printf("%d\n", ans);
        ans = 0;
    }
    return 0;
}
 