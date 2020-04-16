#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e3 + 5;
int n, m, a, b, d;
vector<pair<int, int>> adjlist[N];
int ro[N], vis[N];
vector<int> ans;
void dfs(int n, int mn = 1<<20) {
    vis[n]++;
    for (auto it : adjlist[n]) {
        if (!vis[it.first]) {
            mn = min(mn, it.second);
            dfs(it.first, mn);
        }
    }
    if (!adjlist[n].size()) {
        ans.push_back(n);
        ans.push_back(mn);
    }
}
int main() {
    cin.sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b >> d;
        adjlist[a].push_back({ b, d });
        ro[b]++;
    }
    for (int i = 1; i <= n; i++) {
        if (!ro[i]) {
            ans.push_back(i);
            dfs(i);
            if (ans.size() % 3)ans.pop_back();
            if (ans.back() == 1 << 20) {
                ans.pop_back(); ans.pop_back(); ans.pop_back();
            }
        }
    }
    int k = ans.size() / 3;
    printf("%d\n", k);
    for (int i = 0; i < ans.size(); i += 3) {
        printf("%d %d %d\n", ans[i], ans[i + 1], ans[i + 2]);
    }
    return 0;
}

