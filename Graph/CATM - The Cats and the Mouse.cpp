#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, m, t, mr, mc, r1, c1, r2, c2;
int c1_dis[105][105],
	c2_dis[105][105],
	m_dis[105][105];
int dr[] = { 0, -1, 0, 1 }, 
	dc[] = { -1, 0, 1, 0 };

bool ok(int r, int c, int f) {
	if (f == 1 && m_dis[r][c] != 1e5) return 0;
	if (f == 2 && c1_dis[r][c] != 1e5) return 0;
	if (f == 3 && c2_dis[r][c] != 1e5) return 0;
	return r > 0 && c > 0 && r <= n && c <= m;
}

void bfs(int r, int c, int f) {
	queue<pair<int, int>> q;
	q.push({ r, c });

	if(f==1)m_dis[r][c] = 0;
	if(f==2)c1_dis[r][c] = 0;
	if(f==3)c2_dis[r][c] = 0;

	while (q.size()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i], nc = c + dc[i];
			if (ok(nr, nc, f)) {

				if (f == 1)m_dis[nr][nc] = m_dis[r][c] + 1;
				if (f == 2)c1_dis[nr][nc] = c1_dis[r][c] + 1;
				if (f == 3)c2_dis[nr][nc] = c2_dis[r][c] + 1;

				q.push({ nr, nc });
			}
		}
	}
}

void solve() {
	cin >> mr >> mc >> r1 >> c1 >> r2 >> c2;
	bfs(mr, mc, 1);
	bfs(r1, c1, 2);
	bfs(r2, c2, 3);

	int f = 0;
	for (int i = 1; i <= m; i++) {
		if (m_dis[1][i] < min(c1_dis[1][i], c2_dis[1][i])) f = 1;
		if (m_dis[n][i] < min(c1_dis[n][i], c2_dis[n][i])) f = 1;
	}
	for (int i = 1; i <= n; i++) {
		if (m_dis[i][1] < min(c1_dis[i][1], c2_dis[i][1])) f = 1;
		if (m_dis[i][m] < min(c1_dis[i][m], c2_dis[i][m])) f = 1;
	}
	f ? cout << "YES\n" : cout << "NO\n";
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> t;
	while (t--) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				m_dis[i][j] = 1e5;
				c1_dis[i][j] = 1e5;
				c2_dis[i][j] = 1e5;
			}
		}
		solve();
	}

	return 0;
}


