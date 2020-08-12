#include <bits/stdc++.h>
using namespace std;
#define ll long long
int t, st, en;
const int N = 1e4 + 7;
vector<int> adj[N];
int dis[N];
int p[N];

inline void sieve() {
	for (int i = 2; i*i < N; i++) {
		if (p[i])continue;
		for (int j = i+i; j < N; j += i) {
			p[j] = 1;
		}
	}
}

inline bool valid(int a, int b) {
	int cnt = 0;
	while (a) {
		if (a % 10 != b % 10)cnt++;
		a /= 10, b /= 10;
	}
	return cnt == 1;
}

inline void build_graph() {
	vector<int> primes;
	for (int i = 1000; i <= N; i++) {
		if (!p[i]) {
			primes.push_back(i);
		}
	}
	for (int i = 0; i < primes.size(); i++) {
		for (int j = i + 1; j < primes.size(); j++) {
			int u = primes[i], v = primes[j];
			if (valid(v, u)) {
				adj[u].push_back(v);
				adj[v].push_back(u);
			}
		}
	}
}

inline void bfs(int st) {
	queue<int> q;
	q.push(st);
	dis[st] = 0;
	while (q.size()) {
		int u = q.front();
		q.pop();
		for (auto it : adj[u]) if (dis[it] < 0) {
			dis[it] = dis[u] + 1;
			q.push(it);
		}
	}
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	sieve();
	build_graph();
	cin >> t;
	while (t--) {
		memset(dis, -1, sizeof(dis));
		cin >> st >> en;
		bfs(st);
		dis[en] >= 0 ? cout << dis[en] : cout << 0;
		cout << '\n';
	}
	return 0;
}


