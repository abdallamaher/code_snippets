#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 5;
const int mod = (int)1e9 + 7;

int t, n, m, st, en, u, v, w;
int dis[N];
vector<pair<int, int>> adjList[N];

void init(){
    memset(dis, -1, sizeof dis);
    for(int i=0; i<N; i++)
        adjList[i].clear();
}

void Dijkstra(){
    dis[st] = 0;
    priority_queue<pair<int, int>> q;
    q.push({0, st});
    while(q.size()){
        int u = q.top().second;
        int d = -q.top().first;
        q.pop();
        for(auto i: adjList[u]){
            int v = i.second;
            if(dis[v] == -1  || dis[v] > d + i.first){
                dis[v] = d + i.first;
                q.push({-dis[v], v});
            }
        }
    }
}

int main() {
    cin >> t;
    while(t--){
        init();
        cin >> n >> m >> st >> en;
        for(int i=0; i<m; i++){
            cin >> u >> v >> w;
            adjList[u].push_back({w, v});
            adjList[v].push_back({w, u});
        }
        Dijkstra();
        if(~dis[en]) printf("%d\n", dis[en]);
        else printf("NONE\n");
    }
    return 0;
}


