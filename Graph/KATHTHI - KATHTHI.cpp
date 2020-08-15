#include <bits/stdc++.h>
using namespace std;
#define ll long long
int t, n, m;
const int N = 1e3 + 5;
char g[N][N];
int dis[N][N];
int dr[] = { 0, -1, 0, 1 },
	dc[] = { -1, 0, 1, 0 };

bool ok(int r, int c) {
	return r >= 0 && c >= 0 && r < n && c < m;
}

void dij(int r, int c) {
	deque<pair<int, int>> q;
	q.push_back({ r, c });
	dis[r][c] = 0;
	while (q.size()) {
		int r = q.front().first;
		int c = q.front().second;
		int d = dis[r][c];
		q.pop_front();
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i], nc = c + dc[i];
			int w = bool(g[r][c] != g[nr][nc]);
			if (ok(nr, nc) && dis[nr][nc] > d + w) {
				dis[nr][nc] = d + w;
				if (w)q.push_back({ nr, nc });
				else q.push_front({ nr, nc });
			}
		}
	}
}


int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++) 
			for (int j = 0; j < m; j++) {
				cin >> g[i][j]; 
				dis[i][j] = 1e9;
			}
		dij(0, 0);
		cout << dis[n - 1][m - 1] << endl;
	}

	return 0;
}