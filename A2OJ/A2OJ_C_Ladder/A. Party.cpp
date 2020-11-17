#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
const int mod = (int)1e9 + 7;

int n, k, u, v, ans;
int ar[N], vis[N];
vector<int> adjList[N];
vector<int> mangers;

int Dfs(int u, int lev=1){
    ans = max(lev, ans);
    for(auto i: adjList[u]) Dfs(i, lev+1);
}

int main() {
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> u;
        if(u<0) {
            mangers.push_back(i);
        }
        adjList[u].push_back(i);
    }
    for(int i=0; i<mangers.size(); i++){
        Dfs(mangers[i]);
    }
    cout << ans;
    return 0;
}


