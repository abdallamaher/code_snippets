#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e5 + 5;
int n, sum;
int w[N], v[N];
ll dp[105][N];

ll go(int i, int sum) {
    if (sum < 0)return -1e12;
    if (i > n)return 0;
    ll& ret = dp[i][sum];
    if (~ret)return ret;
    ll a = go(i + 1, sum);
    ll b = go(i + 1, sum - w[i]) + v[i];
    return ret = max(a, b);
}

inline void solve() {
    cin >> n >> sum;
    for (int i = 1; i <= n; i++) cin >> w[i] >> v[i];
    memset(dp, -1, sizeof(dp));
    cout << go(1, sum) << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)solve();
}