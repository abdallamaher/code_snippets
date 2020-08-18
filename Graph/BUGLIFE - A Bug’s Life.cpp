#include <bits/stdc++.h>
using namespace std;
#define ll long long
int T, n, m;
const int N = 2e3 + 5;
vector<int> adj[N];
int vis[N], col[N];

void init() {
	for (int i = 0; i <= n; i++)vis[i] = 0, col[i] = 0;
	for (auto& it : adj)it.clear();
}

int dfs(int i, int c) {
	vis[i] = 1;
	col[i] = c;
	int ret = 0;
	for (auto it : adj[i]) {
		if (!vis[it]) ret += dfs(it, c ^ 1);
		else if (col[it] == c)return 1;
	}
	return ret;
}


int bfs(int i) {
	queue<pair<int,int>> q;
	q.push({ i, 0 });
	while (q.size()) {
		int u = q.front().first;
		int c = q.front().second;
		vis[u] = 1;
		col[u] = c;
		q.pop();
		for (auto it : adj[u]) {
			if (!vis[it])q.push({ it, c ^ 1 });
			else if (col[it] == c) return 1;
		}
	}
	return 0;
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d %d", &n, &m);
		init();
		while (m--) {
			int u, v;
			scanf("%d %d", &u, &v);
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		int f = 0;
		for (int i = 1; i <= n; i++) if (!vis[i])
			f += bfs(i);
			//f += dfs(i, 0);
		printf("Scenario #%d:\n", t);
		if (f)puts("Suspicious bugs found!");
		else puts("No suspicious bugs found!");
	}
	return 0;
}

