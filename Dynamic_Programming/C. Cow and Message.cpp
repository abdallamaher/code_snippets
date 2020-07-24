#include <bits/stdc++.h>
using namespace std;
#define ll long long
string s;
int fr[26];
ll dp[26][26];
ll ans;
 
int main() {
	cin.sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> s;
	int n = s.length();
	for (int i = n - 1; i >= 0; --i) {
		for (int j = 0; j < 26; ++j) {
			dp[s[i] - 'a'][j] += fr[j];
		}
 
		fr[s[i] - 'a']++;
	}
 
	for (int i = 0; i < 26; ++i) {
		ans = max(ans, (ll)fr[i]); // for tc: a
		for (int j = 0; j < 26; ++j) {
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans;
	return 0;
}