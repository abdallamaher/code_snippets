#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
string ss, s;
int dp[3003][3003];

int Table() {
    cin >> s >> ss;
    int n = s.size(), m = ss.size();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == ss[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    string ans = "";
    int x = n, y = m;
    while (y != 0 && x != 0) {
        if (dp[x - 1][y] == dp[x][y])
            --x;
        else if (dp[x][y - 1] == dp[x][y])
            --y;
        else {
            ans = ss[y - 1] + ans;
            --x;
            --y;
        }
    }
    cout << ans;
    return 0;
}


pair<int, int> vis[3003][3003];
int solve(int i, int j) {
    if (i==s.size() || j == ss.size())return 0;
    if (~dp[i][j])return dp[i][j];

    if (s[i] == ss[j]) {
        vis[i][j] = { i + 1, j + 1 };
        return dp[i][j] = 1 + solve(i + 1, j + 1);
    }
    
    int a = solve(i + 1, j);
    int b = solve(i, j + 1);
    int ans = max(a, b);
    if (a == ans) {
        vis[i][j] = { i + 1, j };
    }
    else {
        vis[i][j] = { i, j + 1 };
    }
    return dp[i][j] = ans;
}
int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> s >> ss;
    memset(dp, -1, sizeof(dp));
    solve(0, 0);
    pair<int, int> cur = { 0, 0 };
    while (cur.first < s.size() && cur.second < ss.size()) {
        if (s[cur.first]==ss[cur.second]) {
            cout << s[cur.first];
        }
        cur = vis[cur.first][cur.second];
    }
    return 0;
}

