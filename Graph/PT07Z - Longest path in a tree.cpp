#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, u, v;
const int N = 1e4 + 5;
vector<int> adj[N];
int vis[N];
int mxNode, mx;

void dfs(int i, int d) {
	vis[i] = 1;
	if (d > mx)mxNode = i, mx = d;
	for (auto it : adj[i]) if (!vis[it])
		dfs(it, d + 1);
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	while (--n) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 0);
	memset(vis, 0, sizeof vis);
	dfs(mxNode, 0);
	cout << mx << '\n';
	return 0;
}


