#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, m;
vector<int>adj_r[500], adj_b[500];
int mat[500][500];
int f[500];
int dis_r[500], dis_b[500];

void bfs_r(int st) {
	queue<int> q;
	q.push(st);
	dis_r[st] = 1;
	while (q.size()) {
		int u = q.front();
		q.pop();
		for (auto it : adj_r[u]) if (!dis_r[it]) {
			dis_r[it] = dis_r[u] + 1;
			q.push(it);
		}
	}
}

void bfs_b(int st) {
	queue<int> q;
	q.push(st);
	dis_b[st] = 1;
	while (q.size()) {
		int u = q.front();
		q.pop();
		for (auto it : adj_b[u]) if (!dis_b[it]) {
			dis_b[it] = dis_b[u] + 1;
			q.push(it);
		}
	}
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj_r[u].push_back(v);
		adj_r[v].push_back(u);
		mat[u][v] = 1;
		mat[v][u] = 1;
	}
	bfs_r(1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!mat[i][j]) {
				adj_b[i].push_back(j);
				adj_b[j].push_back(i);
			}
		}
	}
	bfs_b(1);
	if (!dis_r[n] || !dis_b[n])cout << -1;
	else cout << max(dis_r[n], dis_b[n]) - 1;
	return 0;
}


