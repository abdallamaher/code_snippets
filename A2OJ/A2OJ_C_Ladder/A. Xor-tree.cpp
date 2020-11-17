#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
const int OO = (int)1e9;

int n, u, v;
int init[N], goal[N], vis[N];
vector<int> adjList[N];
vector<int> ans;

void dfs(int i = 1, int odd = 0, int even = 0, int level = 0) {
    vis[i]++;
    if ((level & 1 && odd )|| (level % 2 == 0 && even)) 
        init[i] ^= 1;
    if (init[i] != goal[i]) {
        ans.push_back(i);
        if (level & 1)odd ^= 1;
        else even ^= 1;
    }
    for (auto it : adjList[i]) {
        if (!vis[it])dfs(it, odd, even, level + 1);
    }
}
int main() {
    cin.sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        cin >> init[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> goal[i];
    }
    dfs();
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}









