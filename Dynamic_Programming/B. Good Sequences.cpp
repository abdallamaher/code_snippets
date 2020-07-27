#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, ans;
const int N = 1e5 + 5;
int ar[N];
int dp[N];
vector<int> facts[N];
int vis[N];

void seive() {
	facts[1].push_back(1);
	for (int i = 2; i < N; i++) {
		if (vis[i])continue;
		for (int j = i; j < N; j += i) {
			facts[j].push_back(i);
			vis[j]++;
		}
	}

}


int main() {
	cin.sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	seive();

	cin >> n;
	for (int i = 0; i < n; i++)cin >> ar[i];

	for (int i = 0; i < n; i++) {
		int mx = 0;

		for (auto it : facts[ar[i]]) {
			mx = max(mx, dp[it] + 1);
		}

		for (auto it : facts[ar[i]]) {
			dp[it] = mx;
		}

		ans = max(mx, ans);
	}

	cout << ans << '\n';
	return 0;
}

