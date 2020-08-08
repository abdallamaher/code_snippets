#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, m;
const int N = 1e5 + 5;
vector<int> adj[N];
int vis[N];
int main() {
	cin.sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	priority_queue<int, vector<int>, greater<int>> q;
	q.push(1);
	vis[1] = 1;
	while (q.size()) {
		int cur = q.top();
		q.pop();
		printf("%d ", cur);
		for (auto e : adj[cur]) if (!vis[e]) {
			vis[e] = 1; q.push(e);
		}
	}
	return 0;
}
