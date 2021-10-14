#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
int x[105], y[105], vis[105];
vector<int> adj[105];

void dfs(int i) {
    vis[i] = 1;
    for (auto& it : adj[i])if (!vis[it]) {
        dfs(it);
    }
}

inline void solve() {
    cin >> n;
    for (int i = 0; i < n;i++) {
        cin >> x[i] >> y[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (x[i] == x[j] || y[i] == y[j]) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) if (!vis[i]) {
        dfs(i);
        cnt++;
    }
    cout << cnt - 1 << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)solve();
}