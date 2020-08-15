#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, m, sr,sc, er, ec;
char g[30][30];
int dis[30][30];
int dr[] = { 0, -1, 0, 1 },
	dc[] = { -1, 0, 1, 0 };
 
bool ok(int r, int c) {
	return r >= 0 && c >= 0 && r < n && c < m && g[r][c] != 'X';
}
 
void dij(int r, int c) {
	priority_queue<pair<int, pair<int, int>>> q;
	q.push({ 0, {r, c} });
	dis[r][c] = 0;
	while (q.size()) {
		int r = q.top().second.first;
		int c = q.top().second.second;
		int d = -q.top().first;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i], nc = c + dc[i];
			int w = g[nr][nc] - '0';
			if (nr == er && nc == ec)w = 0;
			if (ok(nr, nc) && dis[nr][nc] > d + w) {
				dis[nr][nc] = d + w;
				q.push({ -dis[nr][nc], {nr, nc} });
			}
		}
	}
}
 
int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	cin.sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	//
	while (cin >> m >> n) {
		if (!n && !m)break;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				char c; cin >> c;
				g[i][j] = c;
				if (c == 'S')sr = i, sc = j;
				else if (c == 'D')er = i, ec = j;
 
				dis[i][j] = 1e4;
			}
		}
		dij(sr, sc);
		printf("%d\n", dis[er][ec]);
	}
 
	return 0;
} 