#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, m;
const int N = 2e5 + 5;
int ar[N];
ll dp[N];
ll sum;

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> ar[i];
	}
	sort(ar+1, ar+n+1);

	for (int i = 1; i <= n; i++) {
		sum += ar[i];
		if (i <= m)dp[i] = sum;
		else dp[i] = sum + dp[i - m];

		cout << dp[i] << ' ';
	} 
	return 0;
}

