#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e3 + 5;
int n;
vector<int> v;
int dp[N][N];

int solve(int l, int r) {
    if (l==0 && r==n-1)return 0;
    int& ret = dp[l][r];
    if (~ret)return ret;
    ret = 1e9;

    if (l && r<n-1 && v[l-1] == v[r+1])
        ret = min(ret, solve(l-1, r+1) + 1);
    if (l)
        ret = min(ret, solve(l - 1, r) + 1);
    if (r < n-1)
        ret = min(ret, solve(l, r + 1) + 1);
    return ret;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (v.empty() || v.back() != x)
            v.push_back(x);
    }
    n = v.size();
    memset(dp, -1, sizeof(dp));
    int ans = 1e9;
    for (int i = 0; i < n; i++) {
        ans = min(ans, solve(i, i));
    }
    cout << ans << '\n';
    return 0;
}

