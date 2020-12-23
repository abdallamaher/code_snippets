#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n; cin >> n;
    vector<int> data(n + n), dp(n + n, 1);
    for (int i = 1; i <= n;i++)scanf("%d", &data[i]);
    for (int i = n; i > 0; i--) {
        for (int j = 1; j * j <= i; j++) {
            if (i % j)continue;
            int x = j;
            if (x < i && data[x] < data[i])dp[x] = max(dp[i] + 1, dp[x]);
            x = i / j;
            if (x < i && data[x] < data[i])dp[x] = max(dp[i] + 1, dp[x]);
        }
    }
    int mx = 1;
    for (auto it : dp)mx = max(it, mx);
    cout << mx << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}