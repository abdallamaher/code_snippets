#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e3 + 5;
const int OO = (int)1e9;

int n, m, x, y, cnt;
char g[N][N];
pair<int, int> ar[N];
int dp[N][N][3];

int solve(int i = 0, int p_count = 0, bool mark = 1) {
    if (i >= m) {
        if (p_count >= x && p_count <= y)
            return 0;
        else
            return OO;
    }
    if (~dp[i][p_count][mark])
        return dp[i][p_count][mark];
    int a = OO, b = OO;
    if (p_count >= x || !i)
        b = solve(i + 1, 1, mark ^ 1) + (!mark ? ar[i].first : ar[i].second);
    if (p_count < y)
        a = solve(i + 1, p_count + 1, mark) + (mark ? ar[i].first : ar[i].second);
    return dp[i][p_count][mark] = min(a, b);
}

int main() {
    cin.sync_with_stdio(false);
    cin >> n >> m >> x >> y;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
            if (g[i][j] == '#')ar[j].first++;
            else ar[j].second++;
        }
    }
    memset(dp, -1, sizeof dp);
    printf("%d\n", solve());
    return 0;
}





