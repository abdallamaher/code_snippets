#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
int n, k;
ll dp[2100][2100];

ll solve(int i, int kk) {
    if (i == n) {
        return 1;
    }
    ll& rem = dp[i][kk];
    if (~rem)
        return rem;
    rem = 0;
    for (int j = 1; j <= k/kk; j++) {
        //printf("%d %d %d \n", i, j, k/kk);
        rem += solve(i + 1, j * kk);
        if (rem > mod) rem -= mod;
    }
    return rem;
}
int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> k >> n;
    memset(dp, -1, sizeof(dp));
    cout << solve(0, 1);
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