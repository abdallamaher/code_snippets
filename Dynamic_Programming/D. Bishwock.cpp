#include <bits/stdc++.h>
using namespace std;
#define ll long long
string a, b;
int dp[110][3];

int solve(int i, int p) {
	if (i == a.length())return 0;
	int&ret = dp[i][p];
	if (~ret)return ret;
	//printf("%d %d %d \n", i, a[i], b[i]);
	ret = solve(i + 1, (int)a[i] + (int)b[i]);
	if (p == 2) {	// 2 + 1
		if (a[i])
			ret = max(ret, solve(i + 1, b[i]) + 1);
		if (b[i])
			ret = max(ret, solve(i + 1, a[i]) + 1);
	}
	if (a[i] && b[i] && p) {	// 1 + 2
			ret = max(ret, solve(i + 1, 0) + 1);
	}
	return ret;
}

int go();
int main() {
	cin.sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> a >> b;
	for (auto&it : a) {
		if (it == '0')it = 1;
		else it = 0;
	}
	for (auto&it : b) {
		if (it == '0')it = 1;
		else it = 0;
	}
	memset(dp, -1, sizeof(dp));
	cout << solve(0, 0) << '\n';
	
	return 0;
	go();
}

int go() {
	cin >> a >> b;
	int ar[110] = { 0 };
	for (int i = 0; a[i]; ++i) {
		if (a[i] == '0')ar[i+1]++;
		if (b[i] == '0')ar[i+1]++;
	}


	int ans = 0;
	for (int i = 1; i <= a.length(); i++) {
		if (ar[i] == 2 && ar[i - 1]) {
			ans++;
			ar[i] = 0;
			ar[i - 1]--;
		}
		else if (ar[i] == 2 && ar[i + 1]) {
			ans++;
			ar[i] = 0;
			ar[i + 1]--;
		}
	}
	cout << ans << '\n';
	return 0;
}


