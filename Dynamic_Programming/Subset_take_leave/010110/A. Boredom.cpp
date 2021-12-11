#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
int n, mx;
vector<int> v;
int cnt[N];
ll dp[N];
ll solve(int i = 0) {
    if (i >= n)
        return 0;
    if (~dp[i])
        return dp[i];
    ll& a = dp[i];
    a = solve(i + 1);
    if (v[i] == v[i + 1] - 1)
        a = max(a, solve(i + 2) + 1ll * v[i] * cnt[v[i]]);
    else
        a = max(a, solve(i + 1) + 1ll * v[i] * cnt[v[i]]);

    return a;
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (!cnt[x])
            v.push_back(x);
        cnt[x]++;
    }
    v.push_back(1e9);
    n = v.size() - 1;
    sort(v.begin(), v.end());
    memset(dp, -1, sizeof(dp));
    cout << solve();
    return 0;
}


/*
table
*/
void table() {
    int n; cin >> n;
    int N = 1e5 + 5;
    int ar[N] = {};
    for (int i = 0; i < n;i++) {
        int x; scanf("%d", &x);
        ar[x]++;
    }
    ll dp[N] = {};
    dp[1] = ar[1];
    for (int i = 2;i < N; i++) {
        dp[i] += max(dp[i - 1], (ll)i * ar[i] + dp[i - 2]);
    }
    cout << dp[N - 1] << endl;
}