#include <bits/stdc++.h>
using namespace std;
#define ll long long
int t, sc, ec;
char sr, er;
int dc[] = { -2,-2, -1, -1, 1, 1, 2, 2 },
	dr[] = { -1, 1, -2, 2, 2, -2, 1, -1 };
int dis[9][9];

bool ok(int r, int c) {
	return r > 0 && c > 0 && r <= 8 && c <= 8 && dis[r][c]<0;
}

void bfs(int r, int c) {
	queue<pair<int, int>> q;
	q.push({ r, c });
	dis[r][c] = 0;
	while (q.size()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nr = r + dr[i], nc = c + dc[i];
			if (ok(nr, nc)) {
				dis[nr][nc] = dis[r][c] + 1;
				q.push({ nr, nc });
			}
		}
	}
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> t;
	while (t--) {
		memset(dis, -1, sizeof dis);
		cin >> sr >> sc >> er >> ec;
		int str = (sr - 'a') + 1, enr = (er -'a') + 1;

		bfs(str, sc);
		cout << dis[enr][ec] << '\n';
	}
	return 0;
}


