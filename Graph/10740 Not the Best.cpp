#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, m, s, e, k;
vector<pair<int, int>> adj[105];
int dis[11][105], vis[105];

void dij(int i) {
	priority_queue<pair<int, int>> q;
	q.push({ 0, i });
	dis[0][i] = 0;
	while (q.size()) {
		int u = q.top().second;
		int d = -q.top().first;
		q.pop();
		if (vis[u] > k)continue;
		dis[vis[u]][u] = d; // first time to arrive is the first short, second time is the second short, ..etc
		vis[u]++;
		for (auto it : adj[u]) {
			int v = it.second;
			int w = it.first;
			q.push({ -1 * (d + w), v });
		}
	}
}

void init() {
	memset(dis, -1, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	for (auto& it : adj)it.clear();
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	while (scanf("%d %d", &n, &m)) {
		if (!n && !m)break;
		init();
		scanf("%d %d %d", &s, &e, &k);
		while (m--) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			adj[u].push_back({ w, v });
		}
		dij(s);
		cout << dis[k-1][e] << endl;
	}

	return 0;
}