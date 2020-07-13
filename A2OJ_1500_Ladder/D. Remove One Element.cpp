#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
const int N = 2e5 + 5;
int ar[N];
int dp[3][N];

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
        if (ar[i] > ar[i - 1])dp[0][i] = dp[0][i - 1] + 1;
        else dp[0][i] = 1;
    }

    for (int i = n; i > 0; i--) {
        if (ar[i] < ar[i + 1])dp[1][i] = dp[1][i + 1] + 1;
        else dp[1][i] = 1;
    }


    int ans = 0;
    for (int i = 0; i <= n; i++) {
        if (ar[i - 1] < ar[i + 1])
            ans = max(ans, dp[0][i - 1] + dp[1][i + 1]);
        else
            ans = max(ans, max(dp[0][i], dp[1][i]));
    }
    cout << ans << '\n';
    return 0;
}