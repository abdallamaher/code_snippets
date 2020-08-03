#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, m, x, y;
vector<int> adj[55];
int vis[55];

int dfs(int i) {
	vis[i] = 1;
	int ans = 0;
	for (auto it : adj[i])if (!vis[it])
		ans += dfs(it) + 1;
	return ans;
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			ans += dfs(i);
			//cerr << i << "*********" << x << endl;
		}
	}
	cout << (1LL << ans) << '\n';
	return 0;
}


