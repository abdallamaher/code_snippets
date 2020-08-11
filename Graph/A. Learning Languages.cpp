#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, m, zeros, comp;
vector<int> adj[110];
vector<int> lan[110];
int vis[110];

void dfs(int i) {
	vis[i] = 1;
	for (auto it : adj[i])if (!vis[it])
		dfs(it);
}


inline void bfs(int i) {
	queue<int> q;
	q.push(i);
	vis[i] = 1;
	while (q.size()) {
		int u = q.front();
		q.pop();
		for (auto it : adj[u])if (!vis[it]) {
			q.push(it);
			vis[it] = 1;
		}
	}
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if (x == 0) zeros++;
		while (x--) {
			int l; cin >> l;
			for (auto it : lan[l]) {
				adj[i].push_back(it);
				adj[it].push_back(i);
			}
			lan[l].push_back(i);
		}
	}
	if (zeros == n)return cout << n, 0;
	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			comp++;
			bfs(i);
		}
	}
	cout << comp - 1;
	return 0;
}


