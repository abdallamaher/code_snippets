#include <bits/stdc++.h>
using namespace std;
#define ll long long

int dp[200][200];
int n, m;
int boy[200], girl[200];

int go(int a, int b) {
    if (a == n || b == m)return 0;
    int& ret = dp[a][b];
    if (~ret)return ret;
    if (abs(boy[a] - girl[b]) <= 1)
        return ret = 1 + go(a + 1, b + 1);
    int aa = go(a + 1, b);
    int bb = go(a, b + 1);
    return ret = max(aa, bb);
}

inline void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> boy[i];
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> girl[i];
    }
    sort(boy, boy + n);
    sort(girl, girl + m);
    memset(dp, -1, sizeof(dp));
    cout << go(0, 0);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)solve();
}