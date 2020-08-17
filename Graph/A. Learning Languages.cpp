#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, m, comp, zeros;
const int N = 1e2 + 5;
vector<int>adj[N], lan[N];
int p[N] = { -1 };

int find_parent(int n) {
	vector<int> v;
	while (p[n] > 0) {
		v.push_back(n);
		n = p[n];
	}
	for (int i = 0; i < v.size(); i++)p[v[i]] = n;
	return n;
}

void Union(int u, int v) {
	u = find_parent(u);
	v = find_parent(v);
	if (u == v)return;
	p[u] += p[v];
	p[v] = u;
	comp--;
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d %d", &n, &m);
	comp = n;
	for(int i=1; i<=n; i++) {
		int x; scanf("%d", &x);
		if (!x)zeros++;
		while (x--) {
			int l;  scanf("%d", &l);
			for(auto it: lan[l])Union(i, it);
			lan[l].push_back(i);
		}
	}
	if (zeros == n)return printf("%d\n", n), 0;
	printf("%d\n", comp-1);
	return 0;
}







////////////////////////////////////////////////////





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


