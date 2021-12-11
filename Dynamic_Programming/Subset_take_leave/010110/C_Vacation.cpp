#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
const int N = 1e5 + 5;
int ar[N][4];
int dp[N][4];

int go(int i, int p) {
    if (i == n)return 0;
    int& ret = dp[i][p];
    if (~ret)return ret;
    ret = 0;
    for (int j = 1;j <= 3; j++) {
        if (p == j)continue;
        ret = max(ret, go(i + 1, j) + ar[i][j]);
    }
    return ret;
}

inline void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= 3; j++)
            cin >> ar[i][j];
    }
    memset(dp, -1, sizeof(dp));
    cout << go(0, 0) << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)solve();
}