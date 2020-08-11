#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, d;
const int N = 1e5 + 5;
int ar[N];
vector<int> adj[N];

int dfs(int i, int p, int s) {
	int ret = 0, f = 0;
	for (auto it : adj[i]) if (it != p) {
		ret += dfs(it, i, (ar[it] && s) || s>d ? s+1 : ar[it]);
		f = 1;
	}
	if (!f) return s <= d;
	return ret;
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> d;
	for (int i = 1; i <= n; i++) {
		cin >> ar[i];
	}
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	cout << dfs(1, 0, ar[1]) << '\n';
	return 0;
}


