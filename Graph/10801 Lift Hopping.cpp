#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, e;
int ar[105];
int dis[105];
vector<pair<int, int>> adj[105];

void dij() {
	priority_queue< pair<int, int> > q;
	q.emplace(0, 0);
	dis[0] = 0;
	while (q.size()) {
		int u = q.top().second;
		int d = -q.top().first;
		q.pop();
		for (auto it : adj[u]) {
			int v = it.second;
			int w = it.first;
			if (dis[v] > d + w) {
				dis[v] = d + w;
				q.emplace(-dis[v], v);
			}
		}
	}
}

void init() {
	for (auto& it : adj)it.clear();
	for (int i = 0; i <= 103; i++)dis[i] = 1e5;
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	while (cin >> n >> e) {
		init();
		for (int i = 0; i < n; i++) {
			scanf("%d", &ar[i]);
		}
		vector<vector<int>> elv(105);
		cin.ignore();
		for (int i = 0; i < n; i++) {
			string s;  getline(cin, s);
			stringstream steam(s);
			int f;
			while (steam >> f) {
				elv[i].push_back(f);
			}
		}
		int num = 0;
		for (auto it : elv) {
			for (int i = 0; i < it.size(); i++) {
				for (int j = i + 1; j < it.size(); j++) {
					int u = it[i], v = it[j];
					adj[u].push_back({ ar[num] * abs(v - u) + (!u ? 0 : 60), v });
					adj[v].push_back({ ar[num] * abs(v - u) + (!u ? 0 : 60), u });
				}
			}
			num++;
			if (num > n)break;
		}
		dij();
		if (dis[e] == 1e5)cout << "IMPOSSIBLE";
		else printf("%d", dis[e]);
		cout << '\n';
	}
	return 0;
}