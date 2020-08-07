#include <bits/stdc++.h>
using namespace std;
#define ll long long
int q, n, t, s;
string s1, s2; int x;
map<string, int> mp;
map<string, vector<pair<int, string>>> adj;
map<string, int> dis;
map < string, string> parent;

void dij(string st) {
	priority_queue<pair<int, string>> q;
	q.push({ -mp[st], st });
	dis[st] = mp[st];
	while (q.size()) {
		string u = q.top().second;
		int d = -q.top().first;
		q.pop();
		for (auto it : adj[u]) {
			string v = it.second;
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
	cin.sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> t;
	for (int T = 1; T <= t; T++) {
		mp.clear();
		adj.clear();

		cin >> n;
		for (int i = 0; i < n; i++) {
			string s; int x; cin >> s >> x;
			mp[s] = x;
		}
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> s1 >> s2 >> x;
			adj[s1].push_back({ 2 * x + mp[s2], s2 });
			adj[s2].push_back({ 2 * x + mp[s1], s1 });
		}
		if(T > 1)printf("\n");
		printf("Map #%d\n", T);
		cin >> q;
		for (int i = 1; i <= q; i++) {
			dis.clear();
			parent.clear();

			cin >> s1 >> s2 >> x;
			dij(s1);
			double money = dis[s2];
			printf("Query #%d\n", i);
			
			stack<string> ans;
			while (s2 != s1) {
				ans.push(s2);
				s2 = parent[s2];
			}
			printf("%s", s1.c_str());
			while (ans.size()) {
				printf(" %s", ans.top().c_str());
				ans.pop();
			}
			printf("\n");
			printf("Each passenger has to pay : %.2f taka\n", money * 1.1 / x);
		}
	}

	return 0;
}


/*
2
4
mirpur12 5
farmgate 8
gulistan 10
newmarket 5
4
mirpur12 farmgate 12
mirpur12 newmarket 20
farmgate gulistan 10
newmarket gulistan 8
2
mirpur12 gulistan 30
mirpur12 newmarket 30 
3
uttara 2
farmgate 8
gulistan 10 
2
uttara farmgate 35
farmgate gulistan 10 
1
uttara gulistan 30
*/