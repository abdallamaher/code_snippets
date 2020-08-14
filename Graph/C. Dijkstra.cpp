#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, m;
const int N = 1e5 + 5;
vector<pair<int, int>> adj[N];
ll dis[N];
int parent[N];

void dij() {
	priority_queue<pair<ll, int>> q;
	q.push({ -1, 1 });
	dis[1] = 1;
	while (q.size()) {
		int u = q.top().second;
		ll d = -q.top().first;
		q.pop();

		for (auto it : adj[u]) {
			int v = it.second;
			int w = it.first;
			if (!dis[v] || dis[v] > d + w) {
				dis[v] = d + w;
				parent[v] = u;
				q.push({ -dis[v], v });
			}
		}
	}
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	cin.sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	//
	cin >> n >> m;
	while (m--) {
		int u, v, w; cin >> u >> v >> w;
		adj[u].push_back({ w, v });
		adj[v].push_back({ w, u });
	}
	dij();
	if (!dis[n])return cout << -1, 0;
	stack<int> st;
	while (true) {
		st.push(n);
		if (n == 1)break;
		n = parent[n];
	}
	while (st.size()) {
		printf("%d ", st.top());
		st.pop();
	}
	return 0;
}