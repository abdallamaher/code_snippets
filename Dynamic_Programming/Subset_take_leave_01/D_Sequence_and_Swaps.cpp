#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 505;
int dp[N][N][N];
int ar[N];
int  n, x;

int sol(int i, int lst, int curx) {
    if (i == n)return 0;
    int& ret = dp[i][lst][curx];
    if (~ret)return ret;
    ret = 1e9;
    // build new sequence lst is x  or ar[i]
    // option one : swap if you can
    if (curx >= lst && ar[i] > curx) {
        ret = min(ret, 1 + sol(i + 1, curx, ar[i]));
    }

    // option two : skip
    if (ar[i] >= lst) {
        ret = min(ret, sol(i + 1, ar[i], curx));
    }

    return ret;
}

inline void solve() {
    scanf("%d %d", &n, &x);
    for (int i = 0; i < n; i++)scanf("%d", ar + i);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < N; j++) for (int k = 0;k < N; k++)
            dp[i][j][k] = -1;
    }
    int ans = sol(0, 0, x);
    if (ans == 1e9)puts("-1");
    else printf("%d\n", ans);
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}