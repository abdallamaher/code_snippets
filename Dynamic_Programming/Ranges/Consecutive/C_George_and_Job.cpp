#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 5e3 + 5;
int n, m, k;
ll dp[N][N];
ll ar[N];

ll go(int i, int rem) {
    if (i > n)return -1e15;
    if (i == n || rem == k)return 0;
    ll& ret = dp[i][rem];
    if (~ret)return ret;
    ll leave = go(i + 1, rem);
    ll take = go(i + m, rem + 1) + ar[i + m - 1] - ar[i - 1];
    return ret = max(leave, take);
}

inline void solve() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        if (i)ar[i] += ar[i - 1];
    }
    memset(dp, -1, sizeof(dp));
    cout << go(0, 0);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)solve();
}