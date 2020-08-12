#include <bits/stdc++.h>
using namespace std;
#define ll long long
int sr, sc, er, ec, n;
map<int, vector<int>> adj;
map<pair<int, int>, int> good, dis;
int dr[] = { 0, -1, -1, -1, 0, 1, 1, 1}, 
	dc[] = { -1, -1, 0, 1, 1, 1, 0, -1 };

void bfs(pair<int, int> i) {
	queue <pair<int, int>> q;
	q.push(i);
	dis[i] = 0;
	while (q.size()) {
		pair<int, int> u = q.front();
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nr = u.first + dr[i], nc = u.second + dc[i];
			pair<int, int> v = { nr, nc };
			if (!dis[v] && good[v]) {
				q.push(v);
				dis[v] = dis[u] + 1;
			}
		}
	}
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> sr >> sc >> er >> ec;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int r, s, e; cin >> r >> s >> e;
		for (int i = s; i <= e; i++)good[{r, i}] = 1;
	}

	bfs({ sr, sc });

	dis[{ er, ec }] ? cout << dis[{ er, ec }] : cout << -1;

	return 0;
}


