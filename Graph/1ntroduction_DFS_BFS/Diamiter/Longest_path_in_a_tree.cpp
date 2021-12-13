#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int n;
vector<int> adj[10005];
int mxNode, mxDis;
 
void dfs(int i, int par, int dis) {
    if (dis > mxDis)mxDis = dis, mxNode = i;
    for (auto& it : adj[i])if (it != par)
        dfs(it, i, dis + 1);
}
 
inline void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, -1, 0);
    dfs(mxNode, -1, 0);
    cout << mxDis << endl;
}
 
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)solve();
} 