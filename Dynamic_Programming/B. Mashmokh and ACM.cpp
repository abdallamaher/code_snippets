#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, k;
const int N = 2e3 + 5,mod = 1e9 + 7;
int dp[N][N];
 
int solve(int i=0, int m=1) {
    if (i == n)return 1;
    int& ret = dp[i][m];
    if (~ret)return ret;
 
    ret = 0;
    for (int j = 1; j*m <= k; j++) {
        ret += solve(i + 1, j*m);
        if (ret > mod)ret %= mod;
    }
    return ret;
}
 
int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> k >> n;
    memset(dp, -1, sizeof(dp));
    cout << solve();
    return 0;
}
 

void Table() {
    int K, N;
	cin >> K >> N;
	dp[0][1] = 1;
	for (int n = 0; n < N; n++) {
		for (int k = 1; k <= K; k++) {
			for (int i = k; i <= K; i += k) {
				dp[n + 1][i] += dp[n][k];
				if (dp[n + 1][i] > mod) dp[n + 1][i] -= mod;
			}
		}
	}
	ll sum = 0;
	for (int k = 1; k <= K; k++) {
		sum += dp[N][k];
		if (sum > mod) sum -= mod;
	}
	cout << sum;
}