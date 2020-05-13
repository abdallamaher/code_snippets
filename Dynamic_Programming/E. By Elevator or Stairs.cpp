#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, c;
const int N = 2e5 + 5;
int a[N], b[N];
ll dp[N][3];

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> c;
    for (int i = 1; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        cin >> b[i];
    }
    dp[1][0] = a[1], dp[1][1] = c + b[1];

    cout << "0 " << min(dp[1][0], dp[1][1]) << ' ';
    for (int i = 2; i < n; i++) {
        dp[i][1] = min(dp[i - 1][1] + b[i], dp[i - 1][0] + b[i] + c);
        dp[i][0] = min(dp[i - 1][1] + a[i], dp[i - 1][0] + a[i]);
        cout << min(dp[i][1], dp[i][0]) << ' ';
    }
    return 0;
}