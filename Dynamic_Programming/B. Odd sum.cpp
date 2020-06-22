#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
string n1;
int n;
const int N = 1e5 + 5;
int dp[N][2];
int ar[N];

int solve(int i = 0, int p = 0) {
    if (i == n) {
        if (p == 1)return 0;
        return -1e9;
    }
        
    int& ret = dp[i][p];
    if (~ret)return ret;

    ret = solve(i + 1, p);

    p = (p + ar[i]) & 1;
    ret = max(ret, solve(i + 1, p) + ar[i]);
    return ret;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << solve();
    return 0;
}
