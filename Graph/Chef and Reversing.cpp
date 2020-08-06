#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, k;
const int N = 1e5 + 5;
vector<pair<int, int>> adj[N];
int dis[N];

void dij(int st = 1) {
	priority_queue<pair<int, int>> q;
	q.push({ 0, st });
	dis[st] = 0;
	while (q.size()) {
		int v = q.top().second;
		int d = -q.top().first;
		q.pop();
		for (auto it : adj[v]) {
			int u = it.second;
			int w = it.first;
			if (dis[u]<0 || dis[u] > d + w) {
				dis[u] = d + w;
				q.push({ -dis[u], u });
			}
		}
	}
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> k >> n;
	while (n--) {
		int u, v; cin >> u >> v;
		adj[u].push_back({ 0, v });
		adj[v].push_back({ 1, u });
	}
	memset(dis, -1, sizeof dis);
	dij();
	cout << dis[k] << endl;
	return 0;
}

