#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e3 + 5;
string s;
int n;
int dp[N][N];
int ar[N];

int solve(int l, int r) {
    if (l > r)return 0;
    if (2 * l >= r)return 0;
    int& ret = dp[l][r];
    if (~ret)return ret;

    ret = min(solve(l + 1, r) + ar[l], solve(l, r - 1) + ar[r]);
    return ret;
}
int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        ar[x]++;
    }
    memset(dp, -1, sizeof dp);
    cout << solve(1, 5000);
    return 0;
}