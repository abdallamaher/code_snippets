#include <bits/stdc++.h>
using namespace std;
#define ll long long
int t, row, n, m;
vector<string> g;
int dr[] = { 0, -1, -1, -1, 0, 1, 1, 1 },
	dc[] = { -1, -1, 0, 1, 1, 1, 0, -1 };

bool ok(int r, int c) {
	return r >= 0 && r < n && c >= 0 && c < m && g[r][c] == '1';
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	cin.sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> t; cin.ignore();
	cin.ignore();
	while (t--) {
		g.clear();
		row = 0;
		string s;
		while (getline(cin, s)) {
			if (s == "")break;
			g.push_back(s);
			row++;
		}
		n = g.size(), m = g[0].size();
		int ans = 0;
		int vis[30][30] = {0};
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!vis[i][j] && g[i][j] == '1') {
					int cnt = 1;
					queue<pair<int, int>> q;
					q.push({ i,j });
					vis[i][j] = 1;

					while (q.size()) {
						int r = q.front().first;
						int c = q.front().second;
						q.pop();
						for (int x = 0; x < 8; x++) {
							int nr = r + dr[x], nc = c + dc[x];
							if (ok(nr, nc) && !vis[nr][nc]) {
								q.push({ nr, nc });
								vis[nr][nc] = 1;
								cnt++;
							}
						}
					}
					ans = max(ans, cnt);
				}
			}
		}
		cout << ans << '\n'; 
		if (t)cout << '\n';
	}
	return 0;
}


