#include <bits/stdc++.h>
using namespace std;
#define ll long long
int q, n, m, st, en;
const int N = 1e5 + 7;
vector<pair<int, int>> adj[N];
int dis[N];

void dij(int st) {
	priority_queue<pair<ll, int>> q;
	q.push({ 0, st });
	dis[st] = 0;
	while (q.size()) {
		int u = q.top().second;
		int d = -q.top().first;
		q.pop();
		for (auto it : adj[u]) {
			int v = it.second;
			int w = it.first;
			if (dis[v]<0 || dis[v] > w + d) {
				dis[v] = d + w;
				q.push({ -dis[v], v });
			}
		}
	}
}

void init() {
	memset(dis, -1, sizeof dis);
	for(auto it: adj)
		it.clear();
}


int main() {
	cin.sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> q;
	while (q--) {
		init();
		cin >> n >> m >> st >> en;
		for (int i = 0; i < m; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			adj[u].push_back({ w, v });
			adj[v].push_back({ w, u });
		}
		dij(st);
		if (~dis[en]) printf("%d\n", dis[en]); 
		else puts("NONE");
	}
	return 0;
}

