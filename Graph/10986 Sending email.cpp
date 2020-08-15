#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, m, s, e;
const int N = 1e5 + 5;
vector<pair<int, int>> adj[N];
int dis[N];

void dij(int st) {
	priority_queue<pair<int, int>> q;
	q.push({ 0, st });
	dis[st] = 0;
	while (q.size()) {
		int u = q.top().second;
		int d = -q.top().first;
		q.pop();
		for (auto it : adj[u]) {
			int v = it.second;
			int w = it.first;
			if (dis[v] > d + w) {
				dis[v] = d + w;
				q.push({ -dis[v], v });
			}
		}
	}
}

void init() {
	for (auto& it : adj)it.clear();
	for (int i = 0; i <= n; i++)dis[i] = 1e9;
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int T;  cin >> T;
	for(int t=1; t<=T; t++) {
		cin >> n >> m >> s >> e;
		init();
		while (m--) {
			int u, v, w;
			cin >> u >> v >> w;
			adj[u].push_back({ w, v });
			adj[v].push_back({ w, u });
		}
		dij(s);
		printf("Case #%d: ", t);
		if (dis[e] == 1e9)cout << "unreachable";
		else cout << dis[e];
		cout << '\n';
	}

	return 0;
}