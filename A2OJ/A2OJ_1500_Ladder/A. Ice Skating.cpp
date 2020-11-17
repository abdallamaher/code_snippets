#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
vector<int> adj[105];
int x[105], y[105], vis[105];

void dfs(int i) {
    vis[i]++;
    for (auto it : adj[i])
        if (!vis[it]) dfs(it);
}

void bfs(int i) {
    queue<int> q;
    q.push(i);
    vis[i]++;
    while (q.size()) {
        int f = q.front();
        q.pop();
        for(auto it: adj[f])
            if (!vis[it]) {
                vis[it]++;
                q.push(it);
            }
    }
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (x[i] == x[j] || y[i] == y[j]) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if(!vis[i])
            ans++, dfs(i);
    }
    cout << ans - 1;
    return 0;
}
