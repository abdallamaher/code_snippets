#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 2e5 + 5;
int n;
string a, b;
int dp[N][3];

inline void solve() {
    cin >> n >> a >> b;
    a = '$' + a;
    b = '$' + b;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = dp[i][1] = 0;

        if (a[i] == '2' || a[i] == '1')a[i] = 1;
        else a[i] = 2;

        if (b[i] == '2' || b[i] == '1')b[i] = 1;
        else b[i] = 2;
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 1 && dp[i - 1][0])dp[i][0] = 1;
        if (b[i] == 1 && dp[i - 1][1])dp[i][1] = 1;
        if (a[i] == 2 && b[i] == 2 && dp[i - 1][1])dp[i][0] = 1;
        if (b[i] == 2 && a[i] == 2 && dp[i - 1][0])dp[i][1] = 1;

    }
    if (dp[n][1])cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}