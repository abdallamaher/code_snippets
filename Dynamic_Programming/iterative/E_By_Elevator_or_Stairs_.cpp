#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 2e5 + 5;
ll dp[N][2];
int n, k;
int a[N], b[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> k;
    for (int i = 2; i <= n; i++)cin >> a[i];
    for (int i = 2; i <= n; i++)cin >> b[i];
    for (int i = 2; i <= n;i++) {
        if (i == 2) {
            dp[i][0] = a[i];
            dp[i][1] = b[i] + k;
            continue;
        }
        dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + a[i];
        dp[i][1] = min(dp[i - 1][1], dp[i - 1][0] + k) + b[i];
    }
    for (int i = 1; i <= n; i++)
        cout << min(dp[i][0], dp[i][1]) << ' ';
}