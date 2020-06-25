#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int t, n, p, k;
const int N = 2e5 + 5;
int ar[N];
int dp[N];

int solve(int i) {
    if (i < 1)return 0;
    int& ret = dp[i];
    if (~ret)return ret;

    ret = solve(i - 1) + ar[i];
    if(i-k >= 0)
        ret = min(ret, solve(i - k) + ar[i]);
    return ret;
}
int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> p >> k;
        // k--;
        for (int i = 1; i <= n; ++i) {
            cin >> ar[i];
            dp[i] = -1;
        }
        sort(ar+1, ar + n+1);
        
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if(solve(i) <= p)
                ans = max(ans, i);
        }
        cout << ans << '\n';
        cerr << "*******\n";
    }
    return 0;
}
