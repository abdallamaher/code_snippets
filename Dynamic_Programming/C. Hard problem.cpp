#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
int n;
string ar[2][N];
int a[N];
ll dp[2][N];

ll solve(int p = 0, int i = 0) {
    if (i == n) {
        return 0;
    }
    ll& ret = dp[p][i];
    if (~ret)return ret;

    ret = 1e17;
    if (!i || ar[0][i] >= ar[p][i-1])
        ret = min(ret, solve(0, i+1));

    if (!i || ar[1][i] >= ar[p][i - 1])
        ret = min(ret, solve(1, i+1) + a[i]);

    return ret;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> ar[0][i];
        string& s = ar[1][i];
        s = ar[0][i];
        reverse(s.begin(), s.end());
    }
    memset(dp, -1, sizeof(dp));
    cerr << solve() << endl;
    cout << (solve() == 1e17 ? -1 : solve());
    return 0;
}

