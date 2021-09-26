#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
const int N = 1e5 + 5;
int ar[N];
int dp[N];

int go(int i) {
    if (i > n)return 1e9;
    if (i == n)return 0;
    int& ret = dp[i];
    if (~ret)return ret;
    int a = abs(ar[i] - ar[i + 1]) + go(i + 1);
    int b = abs(ar[i] - ar[i + 2]) + go(i + 2);
    return ret = min(a, b);
}

inline void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++)cin >> ar[i];
    memset(dp, -1, sizeof(dp));
    cout << go(1) << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)solve();
}