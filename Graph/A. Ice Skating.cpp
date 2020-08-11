#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, comp;
int x[110], y[110];
vector<int> adj[110];
int vis[110];

void dfs(int i) {
	vis[i] = 1;
	for (auto it : adj[i])if (!vis[it])
		dfs(it);
}

void bfs(int i) {
	queue<int> q;
	q.push(i);
	while (q.size()) {
		int u = q.front();
		vis[u] = 1;
		q.pop();
		for (auto it : adj[u]) if (!vis[it])
			q.push(it);
	}
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
		for (int j = 0; j < i; j++) {
			if (x[j] == x[i] || y[j] == y[i]) {
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			comp++;
			bfs(i);
		}
	}
	cout << comp - 1 << '\n';
	return 0;
}


