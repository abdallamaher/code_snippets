#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, m;
const int N = 5e2 + 7;
char g[N][N];
int X1, X2, Y1, Y2;
int dr[] = { 0, -1, 0, 1 }, dc[] = { -1, 0, 1, 0 };
int reach;

bool ok(int r, int c) {
	return r <= n && c <= m && r > 0 && c > 0;
}

void dfs(int r, int c) {
	if (g[r][c] == 'X') {
		if (r == X2 && c == Y2) {
			reach = 1;
		}
		return;
	}
	g[r][c] = 'X';
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i], nc = c + dc[i];
		if (ok(nr, nc))dfs(nr, nc);
	}
}


void bfs(int r, int c) {
	queue<pair<int, int>> q;
	q.push({ r, c });
	while (q.size()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		if (g[r][c] == 'X') {
			if (r == X2 && c == Y2) {
				reach = 1;
			}
			continue;
		}
		g[r][c] = 'X';
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i], nc = c + dc[i];
			if (ok(nr, nc)) {
				q.push({ nr, nc });
			}
		}
	}
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> g[i][j];

	cin >> X1 >> Y1 >> X2 >> Y2;
	g[X1][Y1] = '.';

	bfs(X1, Y1);

	if (reach)cout << "YES\n";
	else cout << "NO\n";
	return 0;
}
