#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
const int mod = (int)1e9 + 7;

int n, k, u, v;
int ar[N], vis[N];
vector<int> adjList[N];


int Dfs(int u=1, int cnt=0){
    vis[u]++;
    if(ar[u])cnt++;
    else cnt = 0;
    if(cnt > k) return 0;

    int ans = 0, f = 0;
    for(auto i: adjList[u]){
        if(!vis[i]){
            ans += Dfs(i, cnt);
            f = 1;
        }
    }
    if(!f) return 1;
    return ans;
}

int main() {
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        cin >> ar[i];
    }
    for(int i=0; i<n-1; i++){
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    cout << Dfs();
    return 0;
}


