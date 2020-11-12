#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
vector<int> adj[N];
int vis[N];
vector<int> ans;

void dfs(int n) {
    vis[n]++;
    ans.push_back(n);
    for (auto it : adj[n])if (!vis[it]) {
        dfs(it);
    }
}

int main() {
    int n; cin >> n;
    vector<int> v(n + 5);
    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
        mp[v[i]] = i;
    }
    vector<int> s = v;
    sort(s.begin() + 1, s.begin() + n + 1);

    for (int i = 1; i <= n; i++) {
        if (s[i] != v[i]) {
            adj[mp[s[i]]].push_back(mp[v[i]]);
            adj[mp[v[i]]].push_back(mp[s[i]]);
        }
    }

    vector<vector<int>> res;
    for (int i = 1;i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
            res.push_back(ans);
            ans.clear();
        }
    }
    printf("%d\n", (int)res.size());
    for (auto it : res) {
        printf("%d ", (int)it.size());
        for (int i = 0; i < (int)it.size(); i++)printf("%d%c", it[i], " \n"[i == it.size() - 1]);
    }

    return 0;
}