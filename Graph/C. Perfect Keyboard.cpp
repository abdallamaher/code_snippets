#include <bits/stdc++.h>
using namespace std;
#define ll long long
int t, cycle;
string s;
vector<int> adj[229];
int vis[30];
map<pair<int, int>, bool> mp;
vector<int> ans;

void dfs_cycle(int i, int p) {
	vis[i]++;
	for (auto it : adj[i]) {
		if (vis[it] && p != it) {
			cycle = 1;
			return;
		}
		if (!vis[it]) {
			dfs_cycle(it, i);
		}
	}
}

void dfs(int i, int p) {
	ans.push_back(i);
	for (auto it : adj[i]) {
		if (it != p)dfs(it, i);
	}
}

void init() {
	for (auto &it : adj)it.clear();
	ans.clear();
	memset(vis, 0, sizeof vis);
	cycle = 0;
	mp.clear();
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> t;
	while (t--) {
		init();
		cin >> s;
		int n = s.size();
		for (auto&it : s)it -= 'a';
		
		for (int i = 1; i < n; i++) {
			auto&a = s[i - 1]; auto&b = s[i];
			if (mp[{a, b}])continue;
			mp[{a, b}] = 1;
			mp[{b, a}] = 1;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		dfs_cycle(s[0], -1);
		int st = s[0];
		for (auto i = 0; i < 220; i++) {
			if (adj[i].size() > 2)cycle = 1;
			if (adj[i].size() == 1)st = i;
		}
		if (cycle) {
			cout << "NO\n";
			continue;
		}

		cout << "YES\n";
		dfs(st, -1);
		for (auto it : ans)cout << char(it+'a');
		for (int i = 0; i < 26; i++)if (!vis[i])cout << char(i + 'a');
		cout << '\n';
	}
	return 0;
}

