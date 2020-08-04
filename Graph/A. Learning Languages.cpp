#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, m, ans;
vector<int> adj[110], lan[110];
int vis[110];

void dfs(int i) {
	vis[i] = 1;
	for (auto it : adj[i]) {
		for (auto x : lan[it]) {
			if (!vis[x])dfs(x);
		}
	}
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if (!x)ans++;
		for (int j = 0; j < x; j++) {
			int l; cin >> l;
			adj[i].push_back(l);
			lan[l].push_back(i);
		}
	}
	if (ans == n)return cout << n, 0;
	ans = 0;
	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			ans++;
			dfs(i);
		}
	}
	cout << ans - 1 << '\n';
	return 0;
}


