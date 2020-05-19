#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int q, n;
string s[3];
enum dir { right, down, up };
int dp[3][200005];
int solve(int p=0, int i=0, int d = 0) {
    if (i > n || p > 1)
        return 0;
    if (i == n && p == 1)
        return 1;
    if (~dp[p][i])
        return dp[p][i];
    int ans = 0;
    if (s[p][i] == '2') {
        if(d==0)
            ans += solve(p ^ 1, i, 1);
        else
            ans += solve(p, i + 1, 0);
    }
    if (s[p][i] == '1') {
        if(d == 0)
            ans += solve(p, i + 1, 0);
        else
            return 0;
    }
    return dp[p][i] = ans;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> q;
    while (q--) {
        memset(dp, -1, sizeof(dp));
        cin >> n >> s[0] >> s[1];
        for (auto& c : s[0]) {
            if (c == '2' || c == '1')c = '1';
            else c = '2';
        }
        for (auto& c : s[1]) {
            if (c == '2' || c == '1')c = '1';
            else c = '2';
        }
        if (solve())puts("YES");
        else puts("NO");
    }
    return 0;
}