#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, m, q, st, en;
vector<pair<int, int>> adj[105];
int vis[105];
int cnt;

int dfs(int i, int c) {
	if (i == en) return 1;
	vis[i] = 1; int ret = 0;
	for (auto it : adj[i])if (!vis[it.second] && c == it.first)
		ret |= dfs(it.second, it.first);
	return ret;
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, c; cin >> u >> v >> c;
		adj[u].push_back({ c, v });
		adj[v].push_back({ c, u });
	}
	cin >> q;
	while (q--) {
		cin >> st >> en;
		cnt = 0;
		for (int i = 1; i <= 100; i++) {
			memset(vis, 0, sizeof vis);
			cnt += dfs(st, i);
		}
		cout << cnt << '\n';
	}
	return 0;
}


