#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
int n, u, v;
int ans = -1;
int sz[N];
vector<int> adj[N];

void dfs(int u = 1, int p = 0) {
	sz[u] = 1;
	for (auto it : adj[u])if (p != it) {
		dfs(it, u);
		sz[u] += sz[it];
	}
	if (sz[u] & 1 ^ 1)ans++;
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> u >> v;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	if (n & 1)return cout << -1, 0;

	dfs();

	cout << ans;
	return 0;
}