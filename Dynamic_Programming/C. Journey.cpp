#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
const int N = 1e5 + 5;
vector<int> adjlist[N];
double ans = 0.0;

void dfs(int v = 1, int p = 0, double pr = 1.0, int d = 0) {
	int s = adjlist[v].size() - bool(v != 1);
	if (s == 0) {
		ans += (pr * d);
	}

	pr = pr / s;
	for (auto it : adjlist[v]) {
		if (it != p)
			dfs(it, v, pr, d + 1);
	}
}


int main() {
	cin.sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adjlist[u].push_back(v);
		adjlist[v].push_back(u);
	}
	dfs();
	printf("%.15f\n", ans);
	return 0;
}
