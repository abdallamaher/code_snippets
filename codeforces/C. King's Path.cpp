#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, sx, ex, sy, ey;
map<pair<int, int>, int> mp, dis;
int dc[] = { -1, -1, 0, 1, 1, 1, 0, -1 },
    dr[] = { 0,-1, -1, -1, 0, 1, 1, 1 };

void BFS(int r, int c) {
    dis[{r, c}] = 0;
    queue<pair<int, int>> q;
    q.push({ r, c });
    while (q.size()) {
        auto u = q.front();
        q.pop();
        for (int i = 0; i < 8; i++) {
            int nr = u.first + dr[i], nc = u.second + dc[i];
            if (mp[{nr, nc}] && !dis[{nr, nc}]) {
                dis[{nr, nc}] = dis[u] + 1;
                q.push({ nr, nc });
            }
        }
    }
}

int main() {
    cin.sync_with_stdio(false);
    cin >> sx >> sy >> ex >> ey >> n;
    for (int i = 0; i < n; i++) {
        int r, a, b;
        cin >> r >> a >> b;
        for (int i = a; i <= b; i++) {
            mp[{r, i}]++;
        }
    }
    BFS(sx, sy);
    !dis[{ex, ey}] ? cout << -1 : cout << dis[{ex, ey}];
}