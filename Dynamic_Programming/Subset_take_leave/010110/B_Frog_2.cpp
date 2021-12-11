#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, k;
const int N = 1e5 + 5;
int ar[N];
int dp[N];

int go(int i) {
    if (i > n)return 1e9;
    if (i == n)return 0;
    int& ret = dp[i];
    if (~ret)return ret;
    ret = 1e9;
    for (int j = 1; j <= k; j++) {
        ret = min(ret, abs(ar[i] - ar[i + j]) + go(i + j));
    }
    return ret;
}

inline void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n;i++)cin >> ar[i];
    memset(dp, -1, sizeof(dp));
    cout << go(1) << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)solve();
}