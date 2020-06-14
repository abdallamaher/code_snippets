#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
int n, m, u, v, ans;
vector<int> adjList[N];
int dp[N];

int dfs(int i) {
    if (~dp[i])return dp[i];
    dp[i] = 0;
    for (auto it : adjList[i]) {
        dp[i] = max(dp[i], dfs(it) + 1);
    }
    return dp[i];
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        u--, v--;
        adjList[u].push_back(v);
    }
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++) {
        if (dp[i] == -1)
            ans = max(ans, dfs(i));
    }
    cout << ans;
    return 0;
}
