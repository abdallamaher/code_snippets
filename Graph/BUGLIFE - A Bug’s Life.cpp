#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 5;
const int mod = (int)1e9 + 7;

int n, m, t, u, v;
vector<int> adjList[N];
int vis[N];

void init(){
    memset(vis, -1, sizeof vis);
    memset(adjList, 0, sizeof adjList);
}

bool Bfs(int u){
    vis[u] = 1;
    queue<int> q;
    q.push(u);
    while(q.size()){
        u = q.front();
        q.pop();
        for(auto i: adjList[u]){
            if(~vis[i] && vis[u] != vis[i]) continue;
            if(~vis[i] && vis[u] == vis[i]) return 1;
            vis[i] = !vis[u];
            q.push(i);
        }
    }
    return 0;
}

int main() {
    cin >> t;
    string no = "No suspicious bugs found!", yes = "Suspicious bugs found!";
    for(int a=1; a<=t; a++){
        init();
        cin >> n >> m;
        for(int i=0; i<m; i++){
            cin >> u >> v;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        int flag = 0;
        for(int i=1; i<=n; i++){
            if(vis[i] < 0) flag |= Bfs(i);
        }
        printf("Scenario #%d:\n%s\n", a, !flag ? no.c_str() : yes.c_str());
    }
    return 0;
}


