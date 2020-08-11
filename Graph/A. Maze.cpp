#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, m, k;
char g[550][550];
int dr[] = { 0, -1, 0, 1 }, dc[] = { -1, 0, 1,0 };
int vis[550][550];

bool ok(int r, int c) {
	return r >= 0 && c >= 0 && r < n && c < m&& g[r][c] == '.' && !vis[r][c];
}

void dfs(int r, int c) {
	if (k)k--;
	else g[r][c] = 'X';
	vis[r][c] = 1;
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i], nc = c + dc[i];
		if (ok(nr, nc))dfs(nr, nc);
	}
}


void bfs(int r, int c) {
	queue<pair<int, int>> q;
	q.push({ r, c });
	while (q.size()) {
		pair<int, int> u = q.front();
		r = u.first; c = u.second;
		vis[r][c] = 1;
		if(k)k--;
		else g[r][c] = 'X';
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i], nc = c + dc[i];
			if (ok(nr, nc)) {
				q.push({ nr, nc });
				vis[nr][nc] = 1;
			}
		}
	}
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;

	int kk = 0, r=0, c=0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> g[i][j];
			if (g[i][j] == '.')kk++, r=i, c=j;
		}
	}

	k = kk - k;
	bfs(r, c);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << g[i][j];
		}cout << '\n';
	}

	return 0;
}


