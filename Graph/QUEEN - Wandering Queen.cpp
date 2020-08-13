#include <bits/stdc++.h>
using namespace std;
#define ll long long
int t, n, m, sr, sc, er, ec;
char g[1005][1005];
int dis[1005][1005];
int dr[] = { 0, -1, -1, -1, 0, 1, 1, 1 },
	dc[] = { -1, -1, 0, 1, 1, 1, 0, -1 };

inline bool ok(int r, int c) {
	return r >= 0 && c >= 0 && r < n && c < m && g[r][c] != 'X';
}

void bfs(int r, int c) {
	queue<pair<int, int>> q;
	q.push( { r, c } );
	dis[r][c] = 1;
	while (q.size()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nr = r + dr[i], nc = c + dc[i];
			while ( ok(nr, nc) ) {
				if (dis[nr][nc] == 0) { // never visited
					dis[nr][nc] = dis[r][c] + 1;
					q.push({ nr, nc });
					nr += dr[i], nc += dc[i];
				}
				else if (dis[nr][nc] == dis[r][c] + 1)  // visited by someone with my level but diff direction
					nr += dr[i], nc += dc[i];
				else // visited by someone older, so it has better awnser, let her be in charge, break me
					break;
			}
		}
	}

}
int main() {
	cin.sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> t;
	while (t--) {
		memset(dis, 0, sizeof dis);
		cin >> n >> m;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> g[i][j];
				if (g[i][j] == 'S')sr = i, sc = j;
				else if (g[i][j] == 'F')er = i, ec = j;
			}
		}

		bfs(sr, sc);

		cout << dis[er][ec]-1 << '\n';
		cerr << "**********\n";
	}
	return 0;
}


