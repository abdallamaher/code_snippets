#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, m, cycle;
vector<int> adj[105];
int vis[105];

void dfs(int i, int p) {
	vis[i] = 1;
	for (auto it : adj[i]) {
		if (vis[it] && it != p)cycle++;
		if (!vis[it])dfs(it, i);
	}
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int comp = 0;
	for (int i = 1; i <= n; i++) if (!vis[i]) {
        dfs(1, 0);
        comp++;
    }
	cerr << cycle << endl;
	(comp == 1 && cycle == 2) ? cout << "FHTAGN!\n" : cout << "NO";
	return 0;
}

 