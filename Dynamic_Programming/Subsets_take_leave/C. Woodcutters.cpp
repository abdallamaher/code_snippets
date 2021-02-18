#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
const int N = 2e5 + 5;
int x[N];
int h[N];
int dp[N][4];

int solve(int i = 0, int dir = 0) {
    if (i == n) return 0;
    int& ret = dp[i][dir];
    if (~ret)return ret;
    
    if (i == 0 || i == n - 1)return ret = 1 + solve(i + 1, 0);
    
    ret = solve(i + 1, 0);
    
    if (
        ((dir != 2) && h[i] < x[i] - x[i - 1]) ||    // pre don't fall or fall left
        (dir == 2 && h[i] < x[i] - x[i - 1] - h[i - 1])    // pre fall Right
    ) ret = max(ret, 1 + solve(i + 1, 1));  // cur can fall left

    if (h[i] < x[i + 1] - x[i])
        ret = max(ret, 1 + solve(i + 1, 2));    // cur can fall right
    return ret;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", x + i, h + i);
    }
    memset(dp, -1, sizeof(dp));
    cout << solve();
}