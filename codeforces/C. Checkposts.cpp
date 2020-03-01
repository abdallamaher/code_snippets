#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
const int mod = (int)1e9 + 7;
int n, m, u, v, cnt;
int cost[N];
vector<int> adjList[N], R_adjList[N], ans[N];
int vis[N];
stack<int> Stack;

void DFS1(int i) {
	vis[i]++;
	for (auto it : adjList[i]) {
		if (!vis[it])DFS1(it);
	}
	Stack.push(i);
}

void DFS2(int i) {
	vis[i]++;
	ans[cnt].push_back(i);
	for (auto it : R_adjList[i]) {
		if (!vis[it]) {
			DFS2(it);
		}
	}
}

int main() {
	cin.sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> cost[i];
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		u--, v--;
		adjList[u].push_back(v);
		R_adjList[v].push_back(u);
	}
	// start kosaraku's algorithms
	for (int i = 0; i < n; i++) {
		if (!vis[i]) DFS1(i);
	}
	memset(vis, 0, sizeof vis);
	while (Stack.size()) {
		v = Stack.top();
		Stack.pop();
		if (!vis[v]) {
			DFS2(v);
			cnt++;
		}
	}

	
	ll res1 = 0;ll res2 = 1;
	for (int i = 0; i < cnt; i++) {
		int mn = 1e9 + 100, counter = 0;
		for (auto it : ans[i]) {
			it = cost[it];
			if (it == mn)counter++;
			else if (it < mn) {
				mn = it;
				counter = 1;
			}
		}
		res1 += mn;
		res2 *= counter;
		res2 %= mod;
	}
	printf("%lld %lld\n", res1, res2);
	return 0;
}











