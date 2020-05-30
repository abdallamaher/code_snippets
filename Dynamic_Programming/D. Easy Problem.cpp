#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 6;
int n;
string s;
int ar[N];
char ha[] = "hard";
ll dp[N][5];
ll solve(int i, int cur) {
    if (cur > 3) return 1e17;
    if (i == n)return 0;
    ll& ret = dp[i][cur];
    if (~ret)
        return ret;

    if (s[i] != ha[cur]) {
        return ret = solve(i + 1, cur);
    }
    ll a = solve(i + 1, cur + 1);
    ll b = solve(i + 1, cur) + ar[i];
    return ret = min(a, b);
}
int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof(dp));
    cin >> n >> s;
    for (int i = 0; s[i]; ++i) {
        cin >> ar[i];
    }
    cout << solve(0, 0);
    return 0;
}