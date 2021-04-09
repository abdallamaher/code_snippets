#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
const int N = 1e3 + 5;
ll dp[3][N][N];
int n, k;

ll go(int dir, int col, int force) {
    if (force == 1 || col < 0 || col == n)return 0;
    ll& ret = dp[dir][col][force];
    if (ret)return ret;
    if (dir) {
        ret += 1 + go(0, col - 1, force - 1);
        ret += go(1, col + 1, force);
    }
    else {
        ret += go(0, col - 1, force);
        ret += 1 + go(1, col + 1, force - 1);
    }
    return ret = ret % mod;
}

inline void solve() {
    scanf("%d %d", &n, &k);
    memset(dp, 0, sizeof(dp));
    cout << 1 + go(1, 0, k) << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}